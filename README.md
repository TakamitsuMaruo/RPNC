# RPNC
RPN(逆ポーランド記法)で書かれた四則演算+αのコンパイラです.   
x86-64に対応したアセンブリを吐きます.(多分)    

# Files　　
of.h, of.c : いちいちtab文字とか改行とか出力するのが面倒なので作りました.  
main.c : コンパイラ本体です.ここでコンパイルの9割をやってます.  
makefile : 適当に書いたのでビルドに使えないかもしれない.  
license : MIT  

# Make
`$ make release`  

# Usage  
`$ ./rpnc <expression> > <assembly file>.s`  
のあと  
`$ cc -o <assembly file> <assembly file>.s`  
でどうぞ  

Note:  
  各トークンの間に1つ以上のスペースを入れてください.
