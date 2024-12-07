#include "piqen.hpp"

using Qentem::JSON;
using Qentem::StringStream;
using Qentem::StringUtils;
using Qentem::Template;
using Qentem::Value;

/*
 * I made a fuction that does not copy anything, nor convert
 * it, then I realized that python stores strings in multiple encoding (UTF8,
 * 16, 32) at the same time for the template and the data, depending on the
 * characters inside strings, which made everything hard to try and unify,
 * But since Python is not about performance, I made this function in away that
 * is more stable, and simple.
 */

static PyObject *PiQenRender(PyObject *self, PyObject *args) {
    using QTagBit = Qentem::Array<Qentem::Tags::TagBit>;
    using QHArray = Qentem::HArray<Qentem::String<char>, QTagBit>;

    const char *content;
    const char *data;
    const char *name;

    if (PyArg_ParseTuple(args, "ss|s", &content, &data, &name)) {
        static QHArray            cache;
        static StringStream<char> stream;
        static QTagBit            tags_cache;
        QTagBit                  *tags;

        stream.Clear();

        if (name != nullptr) {
            tags = &(cache.Get(name, Qentem::StringUtils::Count(name)));
        } else {
            tags_cache.Clear();
            tags = &tags_cache;
        }

        const Value<char> value = JSON::Parse(data, StringUtils::Count(data));
        Template::Render(content, StringUtils::Count(content), value, stream, *tags);

        return PyUnicode_DecodeUTF8(stream.First(), Py_ssize_t(stream.Length()), nullptr);
    }

    return nullptr;
}
