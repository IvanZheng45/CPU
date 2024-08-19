\documentclass{article}
\usepackage{amsmath}

\begin{document}

\section*{Assembly Instructions}

\subsection*{Instructions}
\begin{tabbing}
\hspace{2cm} \= \hspace{4cm} \= \kill
\texttt{SET (x, y), (R, G, B)} \> \text{Set color values for coordinates.} \\
\texttt{MOV AX, BX} \> \text{Move the value from register BX to register AX.} \\
\texttt{ADD AX, BX} \> \text{Add the value of register BX to register AX.} \\
\texttt{SUB AX, BX} \> \text{Subtract the value of register BX from register AX.} \\
\texttt{MUL AX, BX} \> \text{Multiply the value of register AX by the value of register BX.} \\
\texttt{DIV AX, BX} \> \text{Divide the value of register AX by the value of register BX.} \\
\texttt{INC AX} \> \text{Increment the value of register AX by 1.} \\
\texttt{DEC AX} \> \text{Decrement the value of register AX by 1.} \\
\texttt{BEQ AX, BX, IMM} \> \text{Branch to IMM if the value of register AX is equal to the value of register BX.} \\
\texttt{BNE AX, BX, IMM} \> \text{Branch to IMM if the value of register AX is not equal to the value of register BX.} \\
\texttt{BGEZ AX, IMM} \> \text{Branch to IMM if the value of register AX is greater than or equal to zero.} \\
\texttt{BLTZ AX, IMM} \> \text{Branch to IMM if the value of register AX is less than zero.} \\
\texttt{AND AX, BX} \> \text{Perform a bitwise AND operation between the values of registers AX and BX.} \\
\texttt{XOR AX, BX} \> \text{Perform a bitwise XOR operation between the values of registers AX and BX.} \\
\texttt{NOT AX} \> \text{Perform a bitwise NOT operation on the value of register AX.} \\
\texttt{PUSH AX} \> \text{Push the value of register AX onto the stack.} \\
\texttt{POP AX} \> \text{Pop the top value from the stack into register AX.} \\
\end{tabbing}

\end{document}
