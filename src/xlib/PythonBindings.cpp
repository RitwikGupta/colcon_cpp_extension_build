//
//  PythonBindings.cpp
//

#include <Python.h>
#include <numpy/arrayobject.h>

#include "nothing.h"

static char module_docstring[] = "This module exposes C++ code to Python";

static PyObject *xlib_test(PyObject *self, PyObject *args)
{
    long test_long = 100L;
    /* Return the sequence handle */
    PyObject *ret = Py_BuildValue("L", test_long);
    return ret;
}

/* Expose the functions to the Python module
 * Note that all methods here only use varargs.
 * In order to use kwargs, use METH_VARARGS | METH_KEYWORDS
 */
static PyMethodDef module_methods[] = {
    {"xlib_test", xlib_test, METH_VARARGS, "Random test method, returns a Python long integer."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef XLib = {
    PyModuleDef_HEAD_INIT,
    "xlib",
    "",
    -1,
    module_methods
};

/* This function has to be named init<name of lib>
 * with no space
 */
PyMODINIT_FUNC PyInit_xlib(void)
{
     /* This enables numpy. There will be segfaults without it.
     * (I learned this the hard way. It took me a whole day of seg
     * faults to figure it out. Don't be like me. Be better)
     */
    import_array();
    
    return PyModule_Create(&XLib);
    
}
