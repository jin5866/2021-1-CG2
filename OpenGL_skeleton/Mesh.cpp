#include "Mesh.h"
#include"MyMath.h"
#include<iostream>
#include <fstream>

void Mesh::setFaceNormal()
{
	if (v.size() == 0) return;

	n.clear();
	for (auto& face : faces) {
		std::vector<GLfloat> result;
		if (face.size() >= 3) {
			std::vector<GLfloat>& v0 = v[face[0][0]];
			std::vector<GLfloat>& v1 = v[face[1][0]];
			std::vector<GLfloat>& v2 = v[face[2][0]];

			std::vector<GLfloat> s0 = v1 - v0;
			std::vector<GLfloat> s1 = v2 - v0;
			std::vector<GLfloat> cs = cross(s1, s0);
			result = normalize(cs);

		}
		n.push_back(result);

	}

	return;
}

Mesh::Mesh(const std::string texFile)
{
	std::ifstream ifs;
	ifs.open(texFile);
	std::string line;
	while (ifs)
	{
		std::getline(ifs, line);
		
		if (line.length() <= 1) continue;

		if (line[0] == 'v') {
			if (line[1] == 'n') {
				//vn
			}
			else if (line[1] == 't') {
				//vt
			}
			else {
				//v
				std::vector<GLfloat> rev;
				int n1 = line.find(' ', 2);
				int n2 = line.find(' ', n1 + 1);
				//int n3 = line.find(' ', n2 + 1);

				rev.push_back(std::stof(line.substr(2, n1 - 2)));
				rev.push_back(std::stof(line.substr(n1 + 1, n2 - n1 - 1)));
				rev.push_back(std::stof(line.substr(n2 + 1, line.size() - n2 - 1)));

				//std::cout << rev[0]<<" "<<rev[1]<<" "<<rev[2] << std::endl;

				v.push_back(rev);
			}
		}
		else if (line[0] == 'f') {
			//f
			int last = 2;

			int pos;
			std::vector<std::vector<GLint>> ref;

			while ((pos = line.find(' ', last)) != std::string::npos) {
				std::string sub = line.substr(last, pos - last);
				std::cout << sub << std::endl;
				std::vector<GLint> ver;
				int sublast = 0;
				int subpos;
				while ((subpos = sub.find('/', sublast)) != std::string::npos) {
					std::string subsub = sub.substr(sublast, subpos - sublast);
					ver.push_back(std::stoi(subsub) - 1);
					//std::cout << subsub << std::endl;
					sublast = subpos + 1;
				}

				std::string subsub = sub.substr(sublast, sub.size() - sublast);
				ver.push_back(std::stoi(subsub) - 1);
				//std::cout << subsub << std::endl;

				ver.resize(3, 0);
				ref.push_back(ver);
				last = pos + 1;

			}
		
			faces.push_back(ref);

		}

		//std::cout << line << std::endl;
	}
	setFaceNormal();
	ifs.close();
	
}

//Mesh::Mesh(const char* texFile)
//{
//}
