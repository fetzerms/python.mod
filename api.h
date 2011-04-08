#ifndef _API_H_
#define _API_H_

#include <Python.h>
#include "khash.h"
#include "../module.h"

#define MODULE_NAME			"python"
#define MODULE_VER_MAJOR	0
#define MODULE_VER_MINOR	1
#define MAKING_PYTHON

#define API_METHOD			(PyObject *self, PyObject *args)

typedef uint32_t callback_id_t;
typedef struct {
	callback_id_t	id;
	char			*name;
	PyThreadState	*subint;
	PyObject		*callable;
} callback_t;

PyObject * api_bind API_METHOD;
PyObject * api_putlog API_METHOD;

/* khash needs access to stdlib */
#undef malloc
#undef free
KHASH_MAP_INIT_INT(callbacks, callback_t);

#endif
