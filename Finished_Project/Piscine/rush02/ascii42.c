int main(int argc, char **argv)
{
	(void)argc;
	int i;

	i = 0;
	while(argv[1] != '\0')
	{
		argv[1][i] += 42;
		write(1, &argv[1][i], 1);
		i++;
	}
	return (0);
}
