<h1 align=center>
Libft Special Edition
</h1>

As shown in repo description, this project is an x86-64 inline assembly version of the classic 42 School mini-C-library.

I worked on it for a long time throughout my Common Core & it has went through a great many transformations. I myself went through a great, rather Dunning-Kruger-like transformation during this period. In the beginning I was happy if something eventually got printed, but I gained more and more confidence over time and built up a set of quite a few functions.

**Only quite recently did I realize that this project was, purely on a conceptual level, an extremely bad idea**. I finished it partly out of spite and partly for educational reasons, but it came to be something I just conceptually *cannot agree with*. Not because assembly language is impractical or complicated - which can be true, but in this same repo you will find a similar project `libasm`, which makes much more sense. But `libasm` is "barebones" assembly.

In regular assembly, you might write code that is clumsy or stupid, but you are on your own turf and fully in control from beginning to the end. In *inline* assembly, however, you are working on a borrowed turf in a foreign territory. It feels like you are an intruder in compiler's world and *almost anything* you do in this situation can only cause harm. Ideally, you want to enter this danger zone only if you must, do what you must, and leave as fast as you can. In other words, how inline assembly is *meant to be used* is the exact opposite of the purpose of this project.

Great outlooks.

The more I worked on the project, the more I realized just how many things can (will) go wrong - and seemingly all solutions were pointing towards abandoning assembly altogether. *How about doing it in C instead?* The more I refused this (what other choice did I have?), the more brittle everything became.

The biggest pain point was definitely **function calls**. With inline assembly, you have the unfortunate setup where your code is a black box to the compiler, and your *eventual* environment is also mostly a black box to you. Just one of the things you have no clue about when you take over from C is the current stack alignment (this would never happen in normal assembly). Technically, I could perform a weird *dynamic* check with modulo operation and adjust on the fly. But an `asm` block also *hides away calls* and thus might make a function seem like a leaf function when it actually isn't. Although I disabled redzone of any function that ends up using the stack (another shitty situation), this just seemed like too much risk to take.

It was a super hard decision as it's completely against the spirit of the project, but I eventually decided to factor all function calls out of assembly and do them in C. Consequently, I tried to separate the *business logic* of the functions from any calls necessary so I can keep them in asm, which gave the project a weird functional feeling. For functions like `strmapi` which consist of nothing but function calls in a loop, I had no choice but to entirely leave them in C. An inline assembly version of such a function just doesn't make sense.

To sum things up, this project is extremely brittle. It isn't faster than a normal libft, it definitely isn't simpler than a normal libft, and it's going to be subpar to *any* C version which eventually gets translated by a compiler. I wouldn't recommend anyone to do this project after me - if you are interested in assembly, go do `libasm` instead. That said, the *process* of doing it was quite enjoyable, and I do think I left with some lessons learned.