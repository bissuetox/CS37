#include <iostream>
using namespace std;

class Version {
public:
	Version();
	int getMajor()const;
	int getMinor()const;
	int getServicePack()const;
	Version& setMajor(const int imajor);
	Version& setMinor(const int iminor);
	Version& setServicePack(const int iservicePack);
private:
	int major, minor, servicePack;
};

Version::Version() {
	major = 0;
	minor = 0;
	servicePack = 0;
}

int Version::getMajor()const {
	return major;
}

int Version::getMinor()const {
	return minor;
}

int Version::getServicePack()const {
	return servicePack;
}

Version& Version::setMajor(const int imajor) {
	major = imajor;
	return *this;
}

Version& Version::setMinor(const int iminor) {
	minor = iminor;
	return *this;
}

Version& Version::setServicePack(const int iservicePack) {
	servicePack = iservicePack;
	return *this;
}

int main() {
	Version v1;
	int major, minor, servicePack;
	cout << "Enter a major, minor and service pack number: " << endl;
	cin >> major >> minor >> servicePack;
	v1.setMajor(major).setMinor(minor).setServicePack(servicePack);
	
	cout << "Major: " << v1.getMajor() << endl;
	cout << "Minor: " << v1.getMinor() << endl;
	cout << "Service Pack: " << v1.getServicePack() << endl;

	system("pause");
}