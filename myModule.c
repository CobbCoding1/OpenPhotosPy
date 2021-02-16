#include <Python.h>

// Fibonacci number function
int Cfib(int n)
{
    if (n < 2)
        return n;
    else
        return Cfib(n-1) + Cfib(n-2);
}

// Add function
double Cadd(double a, double b){
  return a + b;
}

// PyObject Fibonacci function
static PyObject* fib(PyObject* self, PyObject* args)
{
    int n;

    if (!PyArg_ParseTuple(args, "i", &n))
        return NULL;

    return Py_BuildValue("i", Cfib(n));
}

// Pyobject add function
static PyObject* add(PyObject* self, PyObject* args)
{
    double a, b;

    if (!PyArg_ParseTuple(args, "dd", &a, &b))
        return NULL;

    return Py_BuildValue("d", Cadd(a, b));
}

// PyObject version function
static PyObject* version(PyObject* self)
{
    return Py_BuildValue("s", "Version 5.0");
}

static PyMethodDef myMethods[] = {
    {"fib", fib, METH_VARARGS, "Calculate the Fibonacci numbers."},
    {"version", (PyCFunction)version, METH_NOARGS, "Returns the version."},
    {"add", add, METH_VARARGS, "Add two numbers together."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef myModule = {
	PyModuleDef_HEAD_INIT,
	"myModule",
	"Fibonacci Module",
	-1,
	myMethods
};

PyMODINIT_FUNC PyInit_myModule(void)
{
    return PyModule_Create(&myModule);
}
