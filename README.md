PyBind11 submodules in Python

Usage:

```
>>> import test_package
>>> test_package.maths.add(2,5)
7
>>> test_package.test.add(2,5)
7
>>> test_package.python_module
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
AttributeError: module 'test_package' has no attribute 'python_module'
```



based on [https://github.com/pybind/python_example/](https://github.com/pybind/python_example/tree/master)