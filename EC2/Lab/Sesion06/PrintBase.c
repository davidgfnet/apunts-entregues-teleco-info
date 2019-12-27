

void PrintBase (unsigned int x, unsigned int base) {
	if (x == 0) PrintChar '0';
	else {
		while (x != 0) {
			Pusgh (x % base);
			charac++;
			x = x / base;
		}
	}
}
