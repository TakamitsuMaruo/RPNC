# RPNC
RPN(逆ポーランド記法)で書かれた四則演算+αのコンパイラです.   
x86-64に対応したアセンブリを吐きます.(多分)    

# Files
lst.h, lst.c : long型のstackです.コンパイラには必要ありませんでした.(おい)    
of.h, of.c : いちいちtab文字とか改行とか出力するのが面倒なので作りました.  
main.c : コンパイラ本体です.ここでコンパイルの9割をやってます.  
makefile : 適当に書いたのでビルドに使えないかもしれない.

# Usage  
makeして  
`$ ./rpnc <expression> > <file for output>`
でどうぞ  
