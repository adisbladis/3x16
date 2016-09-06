#include <Python.h>

#include "x16.h"

static PyObject *x16_getpowhash(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(64);

#if PY_MAJOR_VERSION >= 3
    x16_hash((char *)PyBytes_AsString((PyObject*) input), output);
#else
    x16_hash((char *)PyString_AsString((PyObject*) input), output);
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 64);
#else
    value = Py_BuildValue("s#", output, 64);
#endif
    PyMem_Free(output);
    return value;
}

static PyMethodDef X16Methods[] = {
    { "getPoWHash", x16_getpowhash, METH_VARARGS, "Returns the proof of work hash using X16 hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef X16Module = {
    PyModuleDef_HEAD_INIT,
    "x16_hash",
    "...",
    -1,
    X16Methods
};

PyMODINIT_FUNC PyInit_x16_hash(void) {
    return PyModule_Create(&X16Module);
}

#else

PyMODINIT_FUNC initx16_hash(void) {
    (void) Py_InitModule("x16_hash", X16Methods);
}
#endif