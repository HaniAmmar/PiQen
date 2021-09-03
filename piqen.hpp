#define PY_SSIZE_T_CLEAN
#include <Python.h>

////////////////////////////////////////////
#include <new>
////////////////////////////////////////////

#include "JSON.hpp"
#include "Template.hpp"

////////////////////////////////////////////
static PyObject *PiQenRender(PyObject *self, PyObject *args);

static PyMethodDef PiQenMethods[] = {
    {"Render", PiQenRender, METH_VARARGS,
     "Return the number of arguments received by the process."},
    {NULL, NULL, 0, NULL}};

static PyModuleDef PiQenModule = {PyModuleDef_HEAD_INIT,
                                  "PiQen",
                                  NULL,
                                  -1,
                                  PiQenMethods,
                                  NULL,
                                  NULL,
                                  NULL,
                                  NULL};

PyMODINIT_FUNC PyInit_PiQen(void) { return PyModule_Create(&PiQenModule); }
