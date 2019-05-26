# ft_printf
Here lies the repository of RPAPAGNA in which hold the work of my own
poor process of rewriting libc printf in C

`brought to you by Carls Junior`

entry: (april, 8, 23:52)
using template after failed attempts Ive gained the knowledge through
resarch and study how to use struct and allocate space without leaking
memory with only helper functions.
using pointers and dereferencing them is very resource heavy but im not
familiar with the entire scope of their massive usage.
for me this project is something im not prepared for but Ill jump right
in because theres no other way to do it!

entry: (april, 26, 12:36)
finished a few conversions with ease, primarily the single character
outputs. I have since moved on to the difficult arguments such as strings
and integers, where field width, minimum, and maximum characters are
accounted for in the format string. the algorithms to use for chosing the
proper width and such is proving to be a very tasking problem. fixing one
bug always leads me into two new problems. I've been taking short breaks
and coming back to the same issues, so sometimes I'd need long periods of
reflection and time away to get back on the right track. things are moving
quite well as I can think about solutions both in front of, and away from
the computer. Im slowly understanding the process of algorithm development
all on my own.

entry: (may, 26, 02:06)
started and finished my work for sprintf, not a very hard addition although
working around norm was something that I just have lost the patience for.
Some funcitons can likely be trimmed down to be a tad bit shorter, but
making them funcitonal to my standard was the main priority. The conversions
I finished tonight were for strings, integers, and chars. These main three
will be the ones I predict I will be using in my future projects should it
require an sprintf call.
