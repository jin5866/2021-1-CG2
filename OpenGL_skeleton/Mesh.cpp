#include "Mesh.h"
#include"MyMath.h"
#include<iostream>
#include <fstream>
#include<algorithm>

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

void Mesh::print()
{
	std::cout << "vertex" << std::endl;

	for (auto& i : v) {
		std::cout << "v : " << i[0] << " " << i[1] << " " << i[2] << std::endl;
	}

	std::cout << "face" << std::endl;

	for (auto& face : faces) {
		std::cout << "f : ";
		for (auto& v : face) {
			std::cout << v[0] << "/" << v[1] << "/" << v[2] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "vertextexture" << std::endl;

	for (auto& i : vt) {
		std::cout << "v : " << i[0] << " " << i[1] << " " << i[2] << std::endl;
	}

	std::cout << "vertexnormal" << std::endl;

	for (auto& i : vn) {
		std::cout << "v : " << i[0] << " " << i[1] << " " << i[2] << std::endl;
	}

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
				int last = 2;

				int pos;
				std::vector<GLfloat> revn;
				if (line[line.size() - 1] != ' ') {
					line.push_back(' ');
				}
				while ((pos = line.find(' ', last)) != std::string::npos) {
					std::string sub = line.substr(last, pos - last);
					//std::cout << sub << std::endl;
					GLfloat ver;

					if (sub.size() >= 1) {
						ver = std::stof(sub);
						revn.push_back(ver);
					}
					last = pos + 1;

				}

				//std::cout << rev[0]<<" "<<rev[1]<<" "<<rev[2] << std::endl;

				vn.push_back(revn);
			}
			else if (line[1] == 't') {
				//vt
				int last = 3;

				int pos;
				std::vector<GLfloat> revt;
				if (line[line.size() - 1] != ' ') {
					line.push_back(' ');
				}
				while ((pos = line.find(' ', last)) != std::string::npos) {
					std::string sub = line.substr(last, pos - last);
					//std::cout << sub << std::endl;
					GLfloat ver;

					if (sub.size() >= 1) {
						ver = std::stof(sub);
						revt.push_back(ver);
					}
					last = pos + 1;

				}

				//std::cout << rev[0]<<" "<<rev[1]<<" "<<rev[2] << std::endl;

				vt.push_back(revt);
			}
			else {
				//v
				int last = 2;

				int pos;
				std::vector<GLfloat> rev;
				if (line[line.size() - 1] != ' ') {
					line.push_back(' ');
				}
				while ((pos = line.find(' ', last)) != std::string::npos) {
					std::string sub = line.substr(last, pos - last);
					//std::cout << sub << std::endl;
					GLfloat ver;

					if (sub.size() >= 1) {
						ver = std::stof(sub);
						rev.push_back(ver);
					}
					last = pos + 1;

				}

				//std::cout << rev[0]<<" "<<rev[1]<<" "<<rev[2] << std::endl;

				v.push_back(rev);
			}
		}
		else if (line[0] == 'f') {
			//f
			int last = 2;

			int pos;
			std::vector<std::vector<GLint>> ref;
			if (line[line.size() - 1] != ' ') {
				line.push_back(' ');
			}
			while ((pos = line.find(' ', last)) != std::string::npos) {
				std::string sub = line.substr(last, pos - last);
				//std::cout << sub << std::endl;
				std::vector<GLint> ver;
				int sublast = 0;
				int subpos;
				while ((subpos = sub.find('/', sublast)) != std::string::npos) {
					std::string subsub = sub.substr(sublast, subpos - sublast);
					if (subsub.length() >= 1) {
						ver.push_back(std::stoi(subsub) - 1);
					}
					else {
						ver.push_back(0);
					}
					//std::cout << subsub << std::endl;
					sublast = subpos + 1;
				}

				std::string subsub = sub.substr(sublast, sub.size() - sublast);
				if (subsub.length() >= 1) {
					ver.push_back(std::stoi(subsub) - 1);
				}
				//std::cout << subsub << std::endl;

				ver.resize(3, 0);
				ref.push_back(ver);
				last = pos + 1;

			}
		
			faces.push_back(ref);

		}

		//std::cout << line << std::endl;
	}
	//setFaceNormal();
	if (!vn.empty()) {
		for (auto& face : faces) {
			std::vector<float> re = { 0,0,0 };
			float count = 0;
			for (auto& voff : face) {
				count += 1;
				re = vn[voff[2]] + re;
			}

			n.push_back(re / count);
		}
	}

	//print();
	
	ifs.close();
	
}

//Mesh::Mesh(const char* texFile)
//{
//}
