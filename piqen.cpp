#include "piqen.hpp"

using Qentem::SizeT;
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
    const char *content;
    const char *data;

    if (!PyArg_ParseTuple(args, "ss", &content, &data)) {
        return nullptr;
    }

    const Value<char>        value  = Qentem::JSON::Parse(data, Qentem::StringUtils::Count(data));
    const StringStream<char> stream = Template::Render(content, Qentem::StringUtils::Count(content), value);

    return PyUnicode_DecodeUTF8(stream.First(), static_cast<Py_ssize_t>(stream.Length()), nullptr);
}
