
#include <iostream>
#include "src/Op.h"
#include "src/Timestamp.h"
#include "src/DetachedFile.h"

int main() {

	// EXAMPLE
	const uint8_t text[] = "Hello, World!";
	std::cout << text << std::endl;

	OpSha256 op = OpSha256();
	uint8_t hash[op.length()];
	op.call(text, sizeof(text),hash);
	std::cout << op << std::endl;

	std::ofstream out("output.txt");
	Serialize serialize(&out);
	op.serialize(serialize);
	out.close();


	Timestamp timestamp (text, sizeof(text));

	const uint8_t msg[] = "Hello, you!";
	Timestamp subStamp (msg, sizeof(msg));
	timestamp.ops.insert(std::make_pair(&op,&subStamp));
	std::cout << timestamp << std::endl;

	DetachedFile detached (&op, text, sizeof(text));
	std::cout << detached << std::endl;





	return 0;
}
