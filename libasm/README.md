# libasm

This subdir contains a mini library in x86-64 assembly.

## ABI (Application Binary Interface)

The ABI defines how any compiled code on the platform communicates at the binary level, including (but not limited to) argument passing, return values, stack alignment, register preservation or syscall conventions. You need to respect these conventions in order to effectively communicate with external functions. They will expect (assume) you know and respect these, and in turn you can also work with the same assumptions.

Document for System V ABI reference: https://refspecs.linuxbase.org/elf/x86_64-abi-0.99.pdf

Short summary of the most important stuff:

- Target: x86-64 System V ABI (Linux).
- Arguments are passed in following registers (in order): `rdi`, `rsi`, `rdx`, `rcx`, `r8`, `r9`; return value is stored in `rax`.
- Before returning from a function, you are mandated to restore the stack pointer `rsp` exactly as you have received it.
- Callee-saved registers are: `rbx`, `rbp`, `r12`-`r15`.
    - If you want to use these registers, you are mandated to save the contents (to the stack) before use, and restore before returning from the function.
    - You can mess with every other register content as you want - but all functions you call will do the same! Therefore the contents of these registers are volatile - you can not have *any* assumption of the contents following a `call`.
        - If they happen to work, you were just lucky!
- Stack: need to maintain 16-byte alignment before `call`.
    - This is because some SSE instructions will need and assume this. You cannot know if any external function relies on these.
    - Since `call` itself pushes an 8-byte return address, *you always enter a funtion 8 bytes misaligned*. You will **first need to align this**, and *then* keep the alignment with subsequent operations (`sub`/`add` only multiples of 16 to `rsp`, `push` even times)
        - You can see this with my minimalistic main (in the following case AT&T syntax as I like it more):
    ```
    #include <stdlib.h>
    int main(int argc, char **argv)
    {
        exit(argc);
    }
    ```
    `gcc` translated it like:
    ```
    sub    $0x8,%rsp
    call   1050 <exit@plt>
    ```
    and `clang` like:
    ```
    push   %rax
    call   401030 <exit@plt>
    ```

## Files and functions
- `ft_atoi_base.s`: Parses an integer from a string using a given base
    - Validates the base for valid characters (I have decided this to be between ASCII 48 or `0` and 126 or `~`)
    - Skips whitespaces and skips/interprets one sign
    - Returns 0 on error
- `ft_list.s`:
  - `ft_list_push_front`: Allocates and prepends a node to a list
  - `ft_free_list`: Frees nodes in a list (data free is commented to fit my testing main).
  - `ft_list_size`: Counts nodes.
  - `ft_list_remove_if`: Removes nodes matching `cmp` and frees via `free_fct`.
- `ft_read.s`: Wraps the read syscall and sets `errno` on error.
- `ft_sort.s`: Merge-sorts a linked list using a compare callback.
    - This means, (iteratively) merges pairs of sublists of increasing size: 1→1, 2→2, 4→4, etc.
- `ft_strcmp.s`: Compares two C strings (byte-wise), returns the difference in first different character
- `ft_strcpy.s`: Copies a C string including the null terminator.
- `ft_strdup.s`: Allocates and duplicates a C string using `ft_strlen`/`ft_strcpy`.
- `ft_strlen.s`: Returns the length of a C string.
- `ft_write.s`: Wraps the write syscall and sets `errno` on error.
- `hehe.s`: Dummy function returning 0 (why not)
