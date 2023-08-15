#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void validateElfFile(unsigned char *e_ident);
void printMagicNumbers(unsigned char *e_ident);
void printFileClass(unsigned char *e_ident);
void printDataEncoding(unsigned char *e_ident);
void printFileVersion(unsigned char *e_ident);
void printOSABI(unsigned char *e_ident);
void printABIVersion(unsigned char *e_ident);
void printFileType(unsigned int e_type, unsigned char *e_ident);
void printEntryAddress(unsigned long int e_entry, unsigned char *e_ident);
void closeElfFile(int elf);

int main(int argc, char *argv[])
{
    Elf64_Ehdr *elfHeader;
    int fileDescriptor, bytesRead;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <elf_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    fileDescriptor = open(argv[1], O_RDONLY);
    if (fileDescriptor == -1)
    {
        fprintf(stderr, "Error: Unable to open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    elfHeader = malloc(sizeof(Elf64_Ehdr));
    if (elfHeader == NULL)
    {
        closeElfFile(fileDescriptor);
        fprintf(stderr, "Error: Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    bytesRead = read(fileDescriptor, elfHeader, sizeof(Elf64_Ehdr));
    if (bytesRead == -1)
    {
        free(elfHeader);
        closeElfFile(fileDescriptor);
        fprintf(stderr, "Error: Unable to read file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    validateElfFile(elfHeader->e_ident);
    printf("ELF Header Information:\n");
    printMagicNumbers(elfHeader->e_ident);
    printFileClass(elfHeader->e_ident);
    printDataEncoding(elfHeader->e_ident);
    printFileVersion(elfHeader->e_ident);
    printOSABI(elfHeader->e_ident);
    printABIVersion(elfHeader->e_ident);
    printFileType(elfHeader->e_type, elfHeader->e_ident);
    printEntryAddress(elfHeader->e_entry, elfHeader->e_ident);

    free(elfHeader);
    closeElfFile(fileDescriptor);

    return EXIT_SUCCESS;
}

void validateElfFile(unsigned char *e_ident)
{
    for (int i = 0; i < 4; i++)
    {
        if (e_ident[i] != 127 && e_ident[i] != 'E' && e_ident[i] != 'L' && e_ident[i] != 'F')
        {
            fprintf(stderr, "Error: Not a valid ELF file\n");
            exit(EXIT_FAILURE);
        }
    }
}

void printMagicNumbers(unsigned char *e_ident)
{
    printf("Magic Numbers: ");

    for (int i = 0; i < EI_NIDENT; i++)
    {
        printf("%02x", e_ident[i]);

        if (i == EI_NIDENT - 1)
            printf("\n");
        else
            printf(" ");
    }
}

void printFileClass(unsigned char *e_ident)
{
    printf("File Class: ");

    switch (e_ident[EI_CLASS])
    {
        case ELFCLASSNONE:
            printf("Invalid Class\n");
            break;
        case ELFCLASS32:
            printf("ELF32\n");
            break;
        case ELFCLASS64:
            printf("ELF64\n");
            break;
        default:
            printf("Unknown Class: %x\n", e_ident[EI_CLASS]);
    }
}

void printDataEncoding(unsigned char *e_ident)
{
    printf("Data Encoding: ");

    switch (e_ident[EI_DATA])
    {
        case ELFDATANONE:
            printf("Invalid Encoding\n");
            break;
        case ELFDATA2LSB:
            printf("2's complement, little endian\n");
            break;
        case ELFDATA2MSB:
            printf("2's complement, big endian\n");
            break;
        default:
            printf("Unknown Encoding: %x\n", e_ident[EI_DATA]);
    }
}

void printFileVersion(unsigned char *e_ident)
{
    printf("File Version: %d", e_ident[EI_VERSION]);

    switch (e_ident[EI_VERSION])
    {
        case EV_CURRENT:
            printf(" (Current)\n");
            break;
        default:
            printf("\n");
            break;
    }
}

void printOSABI(unsigned char *e_ident)
{
    printf("OS/ABI: ");

    switch (e_ident[EI_OSABI])
    {
        case ELFOSABI_NONE:
            printf("UNIX - System V\n");
            break;
        case ELFOSABI_LINUX:
            printf("UNIX - Linux\n");
            break;
        case ELFOSABI_FREEBSD:
            printf("UNIX - FreeBSD\n");
            break;
        case ELFOSABI_SOLARIS:
            printf("UNIX - Solaris\n");
            break;
        default:
            printf("Unknown OS/ABI: %x\n", e_ident[EI_OSABI]);
    }
}

void printABIVersion(unsigned char *e_ident)
{
    printf("ABI Version: %d\n", e_ident[EI_ABIVERSION]);
}

void printFileType(unsigned int e_type, unsigned char *e_ident)
{
    if (e_ident[EI_DATA] == ELFDATA2MSB)
        e_type >>= 8;

    printf("File Type: ");

    switch (e_type)
    {
        case ET_NONE:
            printf("None\n");
            break;
        case ET_REL:
            printf("Relocatable File\n");
            break;
        case ET_EXEC:
            printf("Executable File\n");
            break;
        case ET_DYN:
            printf("Shared Object File\n");
            break;
        case ET_CORE:
            printf("Core File\n");
            break;
        default:
            printf("Unknown Type: %x\n", e_type);
    }
}

void printEntryAddress(unsigned long int e_entry, unsigned char *e_ident)
{
    printf("Entry Point Address: ");

    if (e_ident[EI_DATA] == ELFDATA2MSB)
    {
        e_entry = ((e_entry << 8) & 0xFF00FF00) | ((e_entry >> 8) & 0xFF00FF);
        e_entry = (e_entry << 16) | (e_entry >> 16);
    }

    if (e_ident[EI_CLASS] == ELFCLASS32)
        printf("%#x\n", (unsigned int)e_entry);
    else
        printf("%#lx\n", e_entry);
}

void closeElfFile(int elf)
{
    if (close(elf) == -1)
    {
        fprintf(stderr, "Error: Unable to close file descriptor %d\n", elf);
        exit(EXIT_FAILURE);
    }
}
