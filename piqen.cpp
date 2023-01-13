#include "piqen.hpp"

using Qentem::StringStream;
using Qentem::Template;
using Qentem::Value;

/*
 * I have made this fuction in a way that does not copy anything, nor convert
 * it, then I realized that python stores strings in multiple encoding (UTF8,
 * 16, 32) at the same time for the template and the data, depending on the
 * characters inside their strings, which made everything hard to try to unify,
 * and build something that is fast. But since Python is not about performance,
 * I made the code in away that is more stable, and simple.
 */

static PyObject *PiQenRender(PyObject *self, PyObject *args) {
    using QTagBit = Qentem::Array<Qentem::Template::TagBit>;
    using QHArray = Qentem::HArray<QTagBit, char>;

    const char *content;
    const char *data;
    const char *name;

    if (PyArg_ParseTuple(args, "ss|s", &content, &data, &name)) {
        static QHArray                    cache;
        static Qentem::StringStream<char> stream;
        static QTagBit                    tags_cache;
        QTagBit                          *tags;

        stream.Clear();

        if (name != nullptr) {
            tags = &(cache.GetOrAdd(name, Qentem::StringUtils::Count(name)));
        } else {
            tags_cache.Clear();
            tags = &tags_cache;
        }

        const Value<char> value = Qentem::JSON::Parse(data, Qentem::StringUtils::Count(data));
        Template::Render(content, Qentem::StringUtils::Count(content), value, stream, *tags);

        return PyUnicode_DecodeUTF8(stream.First(), static_cast<Py_ssize_t>(stream.Length()), nullptr);
    }

    return nullptr;
}
