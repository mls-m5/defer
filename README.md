# Defer

Single header that implements defer behaviour in c++.

`defer` in this case is schedule something at the end of scope.
This could ease using for example c-libraries without wrapping in
in some class.

## Example

```c++
int main(int argc, char **argv) {
    auto a = create_some_c_object();
    defer(free_some_c_object(a)); // Will be called before function exits
    
    use_c_object(a);
    
    // defer function will be called here.
}
```

## Licence

MIT licence
