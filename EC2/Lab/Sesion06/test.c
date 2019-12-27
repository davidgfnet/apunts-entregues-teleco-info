void PrintChar(char c);

char ConvGen(int i) //i es un número entre 0 y 19
{ if (i <= 9)
return i + '0';
else
return i + 'A' - 10;
}

int main() {
PrintChar ('A');

return 0;
}
