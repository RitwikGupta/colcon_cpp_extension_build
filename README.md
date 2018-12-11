To repro:

1. Run `python setup.py build_ext --inplace` from src/xlib. Validate that the `xlib.so` file is created.
1. Run `colcon build --symlink-install` from the workspace root. Validate that it cannot find `PythonBindings.cpp`
