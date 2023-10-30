#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * display_elf_header - Displays the ELF header information.
 * @filename: The name of the ELF file.
 */
void display_elf_header(const char *filename)
{
	int fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		dprintf(2, "Error: Unable to open file %s\n", filename);
		exit(98);
	}

	Elf64_Ehdr elf_header;
	if (read(fd, &elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
	{
		dprintf(2, "Error: Unable to read ELF header from file %s\n", filename);
		close(fd);
		exit(98);
	}

	if (elf_header.e_ident[EI_MAG0] != ELFMAG0 ||
			elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
			elf_header.e_ident[EI_MAG2] != ELFMAG2 ||
			elf_header.e_ident[EI_MAG3] != ELFMAG3) {
		dprintf(2, "Error: %s is not an ELF file\n", filename);
		close(fd);
		exit(98);
	}

	printf("ELF Header:\n");
	printf("  Magic:   %02x %02x %02x %02x\n",
			elf_header.e_ident[EI_MAG0],
			elf_header.e_ident[EI_MAG1],
			elf_header.e_ident[EI_MAG2],
			elf_header.e_ident[EI_MAG3]);
	printf("  Class:   %s\n",
			elf_header.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" :
			elf_header.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "Invalid class");
	printf("  Data:    %s\n",
			elf_header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
			elf_header.e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" : "Invalid data encoding");
	printf("  Version: %d (current)\n", elf_header.e_ident[EI_VERSION]);
	printf("  OS/ABI:  %s\n",
			elf_header.e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" :
			elf_header.e_ident[EI_OSABI] == ELFOSABI_HPUX ? "UNIX - HP-UX" :
			elf_header.e_ident[EI_OSABI] == ELFOSABI_NETBSD ? "UNIX - NetBSD" :
			elf_header.e_ident[EI_OSABI] == ELFOSABI_LINUX ? "UNIX - Linux" :
			elf_header.e_ident[EI_OSABI] == ELFOSABI_SOLARIS ? "UNIX - Solaris" :
			elf_header.e_ident[EI_OSABI] == ELFOSABI_AIX ? "UNIX - AIX" :
			elf_header.e_ident[EI_OSABI] == ELFOSABI_IRIX ? "UNIX - IRIX" :
			elf_header.e_ident[EI_OSABI] == ELFOSABI_FREEBSD ? "UNIX - FreeBSD" :
			elf_header.e_ident[EI_OSABI] == ELFOSABI_TRU64 ? "UNIX - TRU64" :
			elf_header.e_ident[EI_OSABI] == ELFOSABI_MODESTO ? "Novell - Modesto" :
			elf_header.e_ident[EI_OSABI] == ELFOSABI_OPENBSD ? "UNIX - OpenBSD" : "Invalid OS/ABI");
	printf("  ABI Ver: %d\n", elf_header.e_ident[EI_ABIVERSION]);
	printf("  Type:    %s\n",
			elf_header.e_type == ET_NONE ? "NONE (No file type)" :
			elf_header.e_type == ET_REL ? "REL (Relocatable file)" :
			elf_header.e_type == ET_EXEC ? "EXEC (Executable file)" :
			elf_header.e_type == ET_DYN ? "DYN (Shared object file)" :
			elf_header.e_type == ET_CORE ? "CORE (Core file)" : "Invalid type");
	printf("  Entry:   0x%lx\n", (unsigned long)elf_header.e_entry);

	close(fd);
}

/**
 * main -  Copies the content of one file to another file.
 *
 * @ac: The number of arguments.
 * @av: The array of arguments.
 *
 * Return: 0 on success, various exit codes on failure.
 */

int main(int ac, char **av)
{
	if (ac != 2)
	{
		dprintf(2, "Usage: %s elf_filename\n", av[0]);
		exit(98);
	}

	display_elf_header(av[1]);

	return (0);
}

