#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * print_magic - Prints the magic bytes of the ELF header.
 * @e_ident: The ELF header e_ident array.
 */
void print_magic(unsigned char e_ident[])
{
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
		printf(" %02x", e_ident[i]);
	printf("\n");
}

/**
 * print_elf_header - Prints information from the ELF header.
 * @elf_header: The ELF header structure.
 */
void print_elf_header(Elf64_Ehdr *elf_header)
{
	printf("  Class:                             %s\n",
			elf_header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" :
			elf_header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "Unknown");
	printf("  Data:                              %s\n",
			elf_header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
			elf_header->e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" : "Unknown");
	printf("  Version:                           %d (current)\n", elf_header->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %s\n",
			elf_header->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" :
			elf_header->e_ident[EI_OSABI] == ELFOSABI_HPUX ? "HP-UX" :
			elf_header->e_ident[EI_OSABI] == ELFOSABI_NETBSD ? "NetBSD" : "Unknown");
	printf("  ABI Version:                       %d\n", elf_header->e_ident[EI_ABIVERSION]);
	printf("  Type:                              %s\n",
			elf_header->e_type == ET_REL ? "REL (Relocatable file)" :
			elf_header->e_type == ET_EXEC ? "EXEC (Executable file)" :
			elf_header->e_type == ET_DYN ? "DYN (Shared object file)" :
			elf_header->e_type == ET_CORE ? "CORE (Core file)" : "Unknown");
	printf("  Entry point address:               0x%llx\n", (unsigned long long)elf_header->e_entry);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the arguments.
 * Return: 0 on success, or an appropriate exit code on failure.
 */
int main(int argc, char **argv)
{
	int fln, bytes_read;
	Elf64_Ehdr elf_header;

	if (argc != 2)
	{
		dprintf(2, "Usage: %s elf_filename\n", argv[0]);
		return 98;
	}

	fln = open(argv[1], O_RDONLY);
	if (fln == -1)
	{
		dprintf(2, "Error: Cannot open file '%s'\n", argv[1]);
		return 98;
	}

	bytes_read = read(fln, &elf_header, sizeof(Elf64_Ehdr));
	if (bytes_read != sizeof(Elf64_Ehdr) || elf_header.e_ident[EI_MAG0] != ELFMAG0 ||
			elf_header.e_ident[EI_MAG1] != ELFMAG1 || elf_header.e_ident[EI_MAG2] != ELFMAG2 ||
			elf_header.e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(2, "Error: '%s' is not an ELF file\n", argv[1]);
		close(fln);
		return 98;
	}

	print_magic(elf_header.e_ident);
	print_elf_header(&elf_header);

	close(fln);
	return 0;
}

