# Temperature Monitor Application

Bare-metal-style temperature monitoring logic, built for a PC demo with the
HAL layer mocked.

# Proposed Architecture
![Architecture diagram](docs/temp_monitor_app_arch_diagram_v1.excalidraw.svg)

# Tools Used

- **CMake** — build system (see [CMakeLists.txt](CMakeLists.txt))
- **Catch2** — unit test framework (see [tests/](tests))
- **FakeIt** — mocking framework for the HAL layer (see [tests/](tests))
