# CS452 Homework 4 - Whack-a-Mole
Class: CS452-002 \
Name: Mackenzie Wright \
Email: mackenziewright@u.boisestate.edu

## Project Description
This program utilies multithreading to simulate a game of Whack-a-Mole.

## Building and Running
To build this program you must be in the hw4 directory. From here, you can use the `make` command to compile all the necessary files into the executable `wam`. If you wish to see the GUI format, simply execute `./wam`, and it should show a new window with a lawn and moles that show up as green initially, turn red when whacked, and disapear shortly after. If you'd rather see a textual version of this process, you simply need to clear the DISPLAY variable by running `DISPLAY= ./wam`, and this will show you the same process in a text format. To run valgrind you must first compile the project and then run the vg script using `./vg`. To clear your build after compiling, use the command `make clean`.

## My Experience
Overall, I had a fun time implementing this project, and it taught me a lot about how locks and critical sections are used to make a program with secure multi-threading. I appreciated the breakdown of steps to complete for this project as they allowed me to slowly build my way up to the final product. The hardest part for me in this project was deciding where to add locks and where critical sections of the program were specifically. I knew where critical sections should be, but I had troubles deciding exactly where these sections should start and end. This is because I didn't want them to not protect important sections, but I also didn't want them to extend too far and interfere with other processes. I tested this project by running both the graphical and visual options for this program mutliple times. 

## Known Issues
There are no known issues with this project. 

## Valgrind Report
Below is my valgrind report I generated using the vg script and fltk suppression files provided in the pub directory.

+ valgrind --leak-check=full --show-leak-kinds=all --suppressions=fltk.supp ./wam \
==610226== Memcheck, a memory error detector \
==610226== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al. \
==610226== Using Valgrind-3.26.0 and LibVEX; rerun with -h for copyright info \
==610226== Command: ./wam \
==610226== \ 
==610226== \
==610226== HEAP SUMMARY: \
==610226==     in use at exit: 580,089 bytes in 1,076 blocks \
==610226==   total heap usage: 12,277 allocs, 11,201 frees, 2,205,753 bytes allocated \
==610226== \
==610226== 4 bytes in 1 blocks are still reachable in loss record 3 of 231 \
==610226==    at 0x484782F: malloc (vg_replace_malloc.c:447) \
==610226==    by 0x5557513: ??? (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x55575AD: g_private_get (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x5528C63: g_slice_alloc (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x54F72A1: g_hash_table_new_full (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x551AB82: ??? (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x54D2DC8: ??? (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x400655D: call_init (dl-init.c:70) \
==610226==    by 0x400655D: call_init (dl-init.c:26) \
==610226==    by 0x400664B: _dl_init (dl-init.c:117) \
==610226==    by 0x401EF69: ??? (in /usr/lib64/ld-linux-x86-64.so.2) \
==610226== \
==610226== 22 bytes in 1 blocks are still reachable in loss record 41 of 231 \
==610226==    at 0x484782F: malloc (vg_replace_malloc.c:447) \
==610226==    by 0x4025DDF: malloc (rtld-malloc.h:56) \
==610226==    by 0x4025DDF: strdup (strdup.c:42) \
==610226==    by 0x4016317: _dl_load_cache_lookup (dl-cache.c:517) \
==610226==    by 0x4009F07: _dl_map_object (dl-load.c:2152) \
==610226==    by 0x400D97B: dl_open_worker_begin (dl-open.c:553) \
==610226==    by 0x4002444: _dl_catch_exception (dl-catch.c:237) \
==610226==    by 0x400D04D: dl_open_worker (dl-open.c:782) \
==610226==    by 0x4002444: _dl_catch_exception (dl-catch.c:237) \
==610226==    by 0x400D51E: _dl_open (dl-open.c:903) \
==610226==    by 0x4E9B8FB: dlopen_doit (in /usr/lib64/libc.so.6) \
==610226==    by 0x4002444: _dl_catch_exception (dl-catch.c:237) \
==610226==    by 0x4002592: _dl_catch_error (dl-catch.c:256) \
==610226== \
==610226== 22 bytes in 1 blocks are still reachable in loss record 42 of 231 \
==610226==    at 0x484782F: malloc (vg_replace_malloc.c:447) \
==610226==    by 0x400CDD8: malloc (rtld-malloc.h:56) \
==610226==    by 0x400CDD8: _dl_new_object (dl-object.c:199) \
==610226==    by 0x40086BE: _dl_map_object_from_fd (dl-load.c:1080) \
==610226==    by 0x4009DEE: _dl_map_object (dl-load.c:2286) \
==610226==    by 0x400D97B: dl_open_worker_begin (dl-open.c:553) \
==610226==    by 0x4002444: _dl_catch_exception (dl-catch.c:237) \
==610226==    by 0x400D04D: dl_open_worker (dl-open.c:782) \
==610226==    by 0x4002444: _dl_catch_exception (dl-catch.c:237) \
==610226==    by 0x400D51E: _dl_open (dl-open.c:903) \
==610226==    by 0x4E9B8FB: dlopen_doit (in /usr/lib64/libc.so.6) \
==610226==    by 0x4002444: _dl_catch_exception (dl-catch.c:237) \
==610226==    by 0x4002592: _dl_catch_error (dl-catch.c:256) \
==610226== \
==610226== 32 bytes in 1 blocks are still reachable in loss record 75 of 231 \
==610226==    at 0x484F4A4: calloc (vg_replace_malloc.c:1678) \
==610226==    by 0x550ECE0: g_malloc0 (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x54F32CE: ??? (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x54F72E0: g_hash_table_new_full (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x551AB82: ??? (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x54D2DC8: ??? (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x400655D: call_init (dl-init.c:70) \
==610226==    by 0x400655D: call_init (dl-init.c:26) \
==610226==    by 0x400664B: _dl_init (dl-init.c:117) \
==610226==    by 0x401EF69: ??? (in /usr/lib64/ld-linux-x86-64.so.2) \
==610226== \
==610226== 32 bytes in 1 blocks are still reachable in loss record 76 of 231 \
==610226==    at 0x484F4A4: calloc (vg_replace_malloc.c:1678) \
==610226==    by 0x550ECE0: g_malloc0 (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x54F32CE: ??? (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x54F72E0: g_hash_table_new_full (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x54D2DD1: ??? (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x400655D: call_init (dl-init.c:70) \
==610226==    by 0x400655D: call_init (dl-init.c:26) \
==610226==    by 0x400664B: _dl_init (dl-init.c:117) \
==610226==    by 0x401EF69: ??? (in /usr/lib64/ld-linux-x86-64.so.2) \
==610226== \
==610226== 64 bytes in 1 blocks are still reachable in loss record 111 of 231 \
==610226==    at 0x484F6B8: realloc (vg_replace_malloc.c:1804) \
==610226==    by 0x550EE1F: g_realloc (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x54F32B9: ??? (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x54F72E0: g_hash_table_new_full (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x551AB82: ??? (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x54D2DC8: ??? (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x400655D: call_init (dl-init.c:70) \
==610226==    by 0x400655D: call_init (dl-init.c:26) \
==610226==    by 0x400664B: _dl_init (dl-init.c:117) \
==610226==    by 0x401EF69: ??? (in /usr/lib64/ld-linux-x86-64.so.2) \
==610226== \
==610226== 64 bytes in 1 blocks are still reachable in loss record 112 of 231 \
==610226==    at 0x484F6B8: realloc (vg_replace_malloc.c:1804) \
==610226==    by 0x550EE1F: g_realloc (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x54F32B9: ??? (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x54F72E0: g_hash_table_new_full (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x54D2DD1: ??? (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x400655D: call_init (dl-init.c:70) \
==610226==    by 0x400655D: call_init (dl-init.c:26) \
==610226==    by 0x400664B: _dl_init (dl-init.c:117) \
==610226==    by 0x401EF69: ??? (in /usr/lib64/ld-linux-x86-64.so.2) \
==610226== \
==610226== 80 bytes in 3 blocks are still reachable in loss record 149 of 231 \
==610226==    at 0x484F984: reallocarray (vg_replace_malloc.c:1806) \
==610226==    by 0x48C71B5: ??? (in /usr/lib64/libX11.so.6.4.0) \
==610226==    by 0x48C8752: ??? (in /usr/lib64/libX11.so.6.4.0) \
==610226==    by 0x48C275C: _XlcCreateLC (in /usr/lib64/libX11.so.6.4.0) \
==610226==    by 0x48E81F9: _XlcUtf8Loader (in /usr/lib64/libX11.so.6.4.0) \
==610226==    by 0x48CFB25: _XOpenLC (in /usr/lib64/libX11.so.6.4.0) \
==610226==    by 0x48CFBF2: XSetLocaleModifiers (in /usr/lib64/libX11.so.6.4.0) \
==610226==    by 0x4A63AA6: fl_open_display() (in /usr/lib64/libfltk.so.1.3.8) \
==610226==    by 0x4A6FDD4: Fl_Window::show() (in /usr/lib64/libfltk.so.1.3.8) \
==610226==    by 0x40493A: lawnimp_new (lawnimp.cc:52) \
==610226==    by 0x402DF7: lawn_new (lawn.c:31) \
==610226==    by 0x403075: main (main.c:40) \
==610226== \
==610226== 96 bytes in 1 blocks are still reachable in loss record 150 of 231 \
==610226==    at 0x484782F: malloc (vg_replace_malloc.c:447) \
==610226==    by 0x550EBA8: g_malloc (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x5528C84: g_slice_alloc (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x54F72A1: g_hash_table_new_full (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x551AB82: ??? (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x54D2DC8: ??? (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x400655D: call_init (dl-init.c:70) \
==610226==    by 0x400655D: call_init (dl-init.c:26) \
==610226==    by 0x400664B: _dl_init (dl-init.c:117) \
==610226==    by 0x401EF69: ??? (in /usr/lib64/ld-linux-x86-64.so.2) \
==610226== \
==610226== 96 bytes in 1 blocks are still reachable in loss record 151 of 231 \
==610226==    at 0x484782F: malloc (vg_replace_malloc.c:447) \
==610226==    by 0x550EBA8: g_malloc (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x5528C84: g_slice_alloc (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x54F72A1: g_hash_table_new_full (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x54D2DD1: ??? (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x400655D: call_init (dl-init.c:70) \
==610226==    by 0x400655D: call_init (dl-init.c:26) \
==610226==    by 0x400664B: _dl_init (dl-init.c:117) \
==610226==    by 0x401EF69: ??? (in /usr/lib64/ld-linux-x86-64.so.2) \
==610226== \
==610226== 104 bytes in 3 blocks are still reachable in loss record 152 of 231 \
==610226==    at 0x484F984: reallocarray (vg_replace_malloc.c:1806) \
==610226==    by 0x48BC035: ??? (in /usr/lib64/libX11.so.6.4.0) \
==610226==    by 0x48BDAA4: ??? (in /usr/lib64/libX11.so.6.4.0) \
==610226==    by 0x48BDB00: ??? (in /usr/lib64/libX11.so.6.4.0) \
==610226==    by 0x48C5D27: _XlcCreateLocaleDataBase (in /usr/lib64/libX11.so.6.4.0) \
==610226==    by 0x48C894F: ??? (in /usr/lib64/libX11.so.6.4.0) \
==610226==    by 0x48C8746: ??? (in /usr/lib64/libX11.so.6.4.0) \
==610226==    by 0x48C275C: _XlcCreateLC (in /usr/lib64/libX11.so.6.4.0) \
==610226==    by 0x48E81F9: _XlcUtf8Loader (in /usr/lib64/libX11.so.6.4.0) \
==610226==    by 0x48CFB25: _XOpenLC (in /usr/lib64/libX11.so.6.4.0) \
==610226==    by 0x48CFBF2: XSetLocaleModifiers (in /usr/lib64/libX11.so.6.4.0) \
==610226==    by 0x4A63AA6: fl_open_display() (in /usr/lib64/libfltk.so.1.3.8) \
==610226== \
==610226== 128 bytes in 1 blocks are still reachable in loss record 158 of 231 \
==610226==    at 0x484F984: reallocarray (vg_replace_malloc.c:1806) \ 
==610226==    by 0x48BB7B4: ??? (in /usr/lib64/libX11.so.6.4.0) \
==610226==    by 0x48C6D88: ??? (in /usr/lib64/libX11.so.6.4.0) \
==610226==    by 0x48C8752: ??? (in /usr/lib64/libX11.so.6.4.0) \
==610226==    by 0x48C275C: _XlcCreateLC (in /usr/lib64/libX11.so.6.4.0) \
==610226==    by 0x48E81F9: _XlcUtf8Loader (in /usr/lib64/libX11.so.6.4.0) \
==610226==    by 0x48CFB25: _XOpenLC (in /usr/lib64/libX11.so.6.4.0) \
==610226==    by 0x48CFBF2: XSetLocaleModifiers (in /usr/lib64/libX11.so.6.4.0) \
==610226==    by 0x4A63AA6: fl_open_display() (in /usr/lib64/libfltk.so.1.3.8) \
==610226==    by 0x4A6FDD4: Fl_Window::show() (in /usr/lib64/libfltk.so.1.3.8) \
==610226==    by 0x40493A: lawnimp_new (lawnimp.cc:52) \
==610226==    by 0x402DF7: lawn_new (lawn.c:31) \
==610226== \
==610226== 192 bytes in 2 blocks are still reachable in loss record 181 of 231 \
==610226==    at 0x484F984: reallocarray (vg_replace_malloc.c:1806) \
==610226==    by 0x4895E26: XListFontsWithInfo (in /usr/lib64/libX11.so.6.4.0) \
==610226==    by 0x48EEE7F: ??? (in /usr/lib64/libX11.so.6.4.0) \
==610226==    by 0x48A14F2: XCreateOC (in /usr/lib64/libX11.so.6.4.0) \
==610226==    by 0x4896432: XCreateFontSet (in /usr/lib64/libX11.so.6.4.0) \
==610226==    by 0x4A618F4: ??? (in /usr/lib64/libfltk.so.1.3.8) \
==610226==    by 0x4A632B9: ??? (in /usr/lib64/libfltk.so.1.3.8) \
==610226==    by 0x4A6393B: fl_open_display(_XDisplay*) (in /usr/lib64/libfltk.so.1.3.8) \
==610226==    by 0x4A6FDD4: Fl_Window::show() (in /usr/lib64/libfltk.so.1.3.8) \
==610226==    by 0x40493A: lawnimp_new (lawnimp.cc:52) \
==610226==    by 0x402DF7: lawn_new (lawn.c:31) \
==610226==    by 0x403075: main (main.c:40) \
==610226== \
==610226== 640 bytes in 1 blocks are still reachable in loss record 192 of 231 \
==610226==    at 0x484F984: reallocarray (vg_replace_malloc.c:1806) \
==610226==    by 0x48B4190: XGetVisualInfo (in /usr/lib64/libX11.so.6.4.0) \
==610226==    by 0x4A63910: fl_open_display(_XDisplay*) (in /usr/lib64/libfltk.so.1.3.8) \
==610226==    by 0x4A6FDD4: Fl_Window::show() (in /usr/lib64/libfltk.so.1.3.8) \
==610226==    by 0x40493A: lawnimp_new (lawnimp.cc:52) \
==610226==    by 0x402DF7: lawn_new (lawn.c:31) \
==610226==    by 0x403075: main (main.c:40) \
==610226== \
==610226== 704 bytes in 2 blocks are still reachable in loss record 198 of 231 \
==610226==    at 0x484F984: reallocarray (vg_replace_malloc.c:1806) \
==610226==    by 0x4895D6C: XListFontsWithInfo (in /usr/lib64/libX11.so.6.4.0) \
==610226==    by 0x48EEE7F: ??? (in /usr/lib64/libX11.so.6.4.0) \
==610226==    by 0x48A14F2: XCreateOC (in /usr/lib64/libX11.so.6.4.0) \
==610226==    by 0x4896432: XCreateFontSet (in /usr/lib64/libX11.so.6.4.0) \
==610226==    by 0x4A618F4: ??? (in /usr/lib64/libfltk.so.1.3.8) \
==610226==    by 0x4A632B9: ??? (in /usr/lib64/libfltk.so.1.3.8) \
==610226==    by 0x4A6393B: fl_open_display(_XDisplay*) (in /usr/lib64/libfltk.so.1.3.8) \
==610226==    by 0x4A6FDD4: Fl_Window::show() (in /usr/lib64/libfltk.so.1.3.8) \
==610226==    by 0x40493A: lawnimp_new (lawnimp.cc:52) \
==610226==    by 0x402DF7: lawn_new (lawn.c:31) \
==610226==    by 0x403075: main (main.c:40) \
==610226== \
==610226== 1,207 bytes in 1 blocks are still reachable in loss record 205 of 231 \
==610226==    at 0x484F4A4: calloc (vg_replace_malloc.c:1678) \
==610226==    by 0x400CAE2: calloc (rtld-malloc.h:44) \
==610226==    by 0x400CAE2: _dl_new_object (dl-object.c:92) \
==610226==    by 0x40086BE: _dl_map_object_from_fd (dl-load.c:1080) \
==610226==    by 0x4009DEE: _dl_map_object (dl-load.c:2286) \
==610226==    by 0x400D97B: dl_open_worker_begin (dl-open.c:553) \
==610226==    by 0x4002444: _dl_catch_exception (dl-catch.c:237) \
==610226==    by 0x400D04D: dl_open_worker (dl-open.c:782) \
==610226==    by 0x4002444: _dl_catch_exception (dl-catch.c:237) \
==610226==    by 0x400D51E: _dl_open (dl-open.c:903) \
==610226==    by 0x4E9B8FB: dlopen_doit (in /usr/lib64/libc.so.6) \
==610226==    by 0x4002444: _dl_catch_exception (dl-catch.c:237) \
==610226==    by 0x4002592: _dl_catch_error (dl-catch.c:256) \
==610226== \
==610226== 2,032 bytes in 1 blocks are still reachable in loss record 212 of 231 \
==610226==    at 0x484F4A4: calloc (vg_replace_malloc.c:1678) \
==610226==    by 0x550ECE0: g_malloc0 (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x5528EED: g_slice_alloc (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x54F72A1: g_hash_table_new_full (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x551AB82: ??? (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x54D2DC8: ??? (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x400655D: call_init (dl-init.c:70) \
==610226==    by 0x400655D: call_init (dl-init.c:26) \
==610226==    by 0x400664B: _dl_init (dl-init.c:117) \
==610226==    by 0x401EF69: ??? (in /usr/lib64/ld-linux-x86-64.so.2) \
==610226== \
==610226== 16,384 bytes in 1 blocks are still reachable in loss record 225 of 231 \
==610226==    at 0x484782F: malloc (vg_replace_malloc.c:447) \
==610226==    by 0x550EBA8: g_malloc (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x551AB93: ??? (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x54D2DC8: ??? (in /usr/lib64/libglib-2.0.so.0.6800.4) \
==610226==    by 0x400655D: call_init (dl-init.c:70) \
==610226==    by 0x400655D: call_init (dl-init.c:26) \
==610226==    by 0x400664B: _dl_init (dl-init.c:117) \
==610226==    by 0x401EF69: ??? (in /usr/lib64/ld-linux-x86-64.so.2) \
==610226== \
==610226== LEAK SUMMARY: \
==610226==    definitely lost: 0 bytes in 0 blocks \
==610226==    indirectly lost: 0 bytes in 0 blocks \
==610226==      possibly lost: 0 bytes in 0 blocks \
==610226==    still reachable: 21,903 bytes in 24 blocks \
==610226==         suppressed: 558,186 bytes in 1,052 blocks \
==610226== \
==610226== For lists of detected and suppressed errors, rerun with: -s \
==610226== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0) \