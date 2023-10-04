```asm
 5fa:   55                      push   rbp
 5fb:   48 89 e5                mov    rbp,rsp
 5fe:   b8 2a 00 00 00          mov    eax,0x2a
 603:   5d                      pop    rbp
```
1. rbp(base pointer) => stack top
2. rsp(stack pointer) => rbp
3. 0x2a(42) => eax (戻り値を返す時のレジスタ)
4. stack top => rbp

rbpは関数が呼ばれる時、呼び出し元の関数のスタックフレームのベースポインタを指している
rspは関数が呼ばれる時、新しいスタックフレームのトップを指している