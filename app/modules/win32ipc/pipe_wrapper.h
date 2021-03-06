#pragma once

#include <cstdint>

#ifdef IN
#undef IN
#endif

#ifdef OUT
#undef OUT
#endif


namespace pipe_wrapper {

template <typename T>
struct result {
    T value;
    char const* err_msg;

    static result ok(T value) {
        result r{};
        r.value = value;
        r.err_msg = nullptr;
        return r;
    }

    static result error(char const* err_msg) {
        result r{};
        r.err_msg = err_msg;
        return r;
    }
};

enum class pipe_direction { IN, OUT };

struct pipe {
    uintptr_t read_end_handle;
    uintptr_t write_end_handle;
};

result<pipe> create_pipe(pipe_direction direction);
char const* close_pipe_end(uintptr_t read_end_handle, uintptr_t write_end_handle);

} // namespace pipe_wrapper
