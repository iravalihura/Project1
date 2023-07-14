#include "File.h"

void File::OpenFile(const ios_base::openmode mode)
{
	file.open("InputFile.dat", mode);
	if (!file)
	{
		cerr << "Failed to open the file." <<endl;
		exit(1);
	}
}
