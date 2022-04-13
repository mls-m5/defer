#pragma once

namespace deferimpl {

template <typename F>
class DeferImpl {
public:
    constexpr DeferImpl(F f)
        : f(f) {}

    ~DeferImpl() {
        f();
    }

private:
    F f;
};

// This is needed to make ## operator work with __LINE__
#define DEFER_CONCAT(x, y) x##y
#define DEFER_CONCAT2(x, y) DEFER_CONCAT(x, y)
#define defer(f)                                                               \
    auto DEFER_CONCAT2(deferClass, __LINE__) = deferimpl::DeferImpl([&] { f; });

} // namespace deferimpl
