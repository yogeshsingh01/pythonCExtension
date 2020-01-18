#include <Python.h>

/** Return Factorial */
unsigned long fastfactorial(unsigned int n)
{
  if(n<=1)
    return 1;
  else
    return n * fastfactorial(n-1);
}


/** Modify passed buffer */
void modifybuffer(unsigned char *strptr, unsigned char length)
{
  while(length--)
  {
    *strptr++;
    //strptr++;
  }
}


/**
 * To use fastfactorial we need to create a wrapper
 */
static PyObject* factorial(PyObject* self, PyObject* args)
{
   unsigned int n;
   unsigned long result;
   // We need to parse input arguments i.e. 'integer' to our function
   if (!PyArg_ParseTuple(args,"i",&n))
   {
       return NULL;
   }
   result = fastfactorial(n);// Pass value given to api to function
   // $reference https://docs.python.org/3/c-api/arg.html for type of argument
   // in our case we are using unsigned long hence k
   return Py_BuildValue("k",result);
}

/**
 * To use modifybuffer we need to create a wrapper
 */
static PyObject* IncBuffer(PyObject* self, PyObject* args)
{
    char *s;
    int size;;

    if (!PyArg_ParseTuple(args, "s*i", s,&size))
        return NULL;
    printf("In C \n");
    while(size--)
    {
      printf("%c\n",*s++ );
    }

     Py_RETURN_NONE;
}

/**
 * Now we have to tell python what is our function for this PyMethodDef
 * comes in picture
 * This have four field i.e method name, function pointer, flags, docstring
 * $reference https://docs.python.org/3/c-api/structures.html
 */
static PyMethodDef mainMethods[] =
{
  {"factorial",factorial,METH_VARARGS,"Calculate the factorial of n"},
  {"IncBuffer",IncBuffer,METH_VARARGS,"Increment buffer by 1"},
  {NULL,NULL,0,NULL}
};

/**
 * Its a structure that represent our python module
 * $reference: https://docs.python.org/3/c-api/module.html
 */
static PyModuleDef ymath =
{
 PyModuleDef_HEAD_INIT,
 "ymath","Python C api extension example",
 -1,
 mainMethods
};

/**
 * The PyMODINIT_FUNC return type declares that the method actually returns a
 * PyObject pointer. This is a pointer to the python module itself (which is in
 * the end also a PyObject) which gets created by PyModule_Create .
 * When a module is imported in a python script this method gets called and
 * returns the pointer to the whole Module including all its methods.
 */
PyMODINIT_FUNC PyInit_ymath(void){
 return PyModule_Create(&ymath);
}
