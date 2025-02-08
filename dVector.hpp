#include "include.hpp"

namespace dVector {
	template<typename T>
	class dVector {
		friend class Vevtor3d;
	public:
		dVector(std::vector<T>& vector);

		dVector(const dVector<T>& dVector); 

		dVector();

		~dVector();

		dVector<T>& operator= (const dVector<T>& dVector);

		dVector<T>& operator+= (const dVector<T>& dVector);

		dVector<T>& operator-= (const dVector<T>& dVector);

		void PrintVector();
	private:
		void CreateVector(size_t size);
		T* dvector;
		size_t size;
	};

	template<typename T>
	dVector<T> operator+ (const dVector<T>& dvector1, const dVector<T>& dvector2);

	template<typename T>
	dVector<T> operator- (const dVector<T>& dvector1, const dVector<T>& dvector2);

	//Methods
	template<typename T>
	inline dVector<T>::dVector(std::vector<T>& vector)
	{
		size_t vsize = vector.size();
		size = vsize;
		if (size != 0) {
			dVector::CreateVector(size);
			for (size_t i = 0; i < size; ++i) {
				dvector[i] = vector[i];
			}
		}
		else {
			throw std::invalid_argument("can't be zero size");
		}
	}

	template<typename T>
	inline dVector<T>::dVector(const dVector<T>& dVector)
	{
		size = dVector.size; dVector::CreateVector(size); 
		for (size_t i = 0; i < size; ++i) {
			dvector[i] = dVector.dvector[i];
		}
	}

	template<typename T>
	inline dVector<T>::dVector()
	{
		size = 4;
		dVector::CreateVector(4);
		for (size_t i = 0; i < 3; ++i) {
			dvector[i] = 1;
		}
		dvector[3] = 0;
	}

	template<typename T>
	inline dVector<T>::~dVector()
	{
		delete[] dvector;
	}

	template<typename T>
	inline dVector<T>& dVector<T>::operator=(const dVector& dVector)
	{
		if (this == &dVector) {
			return *this;
		}
		else {
			delete[] dvector;
			size = dVector.size;
			dvector = new T[size];
			for (size_t ind = 0; ind < size; ++ind) {
				dvector[ind] = dVector.dvector[ind];
			}
			return *this;
		}
	}

	template<typename T>
	inline dVector<T>& dVector<T>::operator+=(const dVector& dVector)
	{
		if (size != dVector.size) {
			throw std::invalid_argument("Invalid size of dVector");
		}
		else {
			for (size_t i = 0; i < size; ++i) {
				dvector[i] += dVector.dvector[i];
			}
		}
		return *this;
	}

	template<typename T>
	inline dVector<T>& dVector<T>::operator-=(const dVector& dVector)
	{
		if (size != dVector.size) {
			throw std::invalid_argument("Invalid size of dVector");
		}
		else {
			for (size_t i = 0; i < size; ++i) {
				dvector[i] -= dVector.dvector[i];
			}
		}
		return *this;
	}

	template<typename T>
	inline void dVector<T>::PrintVector()
	{
		std::cout << "(" << " ";
		for (size_t i = 0; i < size - 1; ++i) {
			std::cout << dvector[i] << ", ";
		}
		std::cout << dvector[size - 1] << " )";
	}

	template<typename T>
	inline void dVector<T>::CreateVector(size_t size)
	{
		dvector = new T[size];
	}

	template<typename T>
	inline dVector<T> operator+(const dVector<T>& dvector1, const dVector<T>& dvector2)
	{
		dVector<T> tempVector;
		tempVector = dvector1;
		tempVector += dvector2;
		return tempVector;
	}

	template<typename T>
	inline dVector<T> operator-(const dVector<T>& dvector1, const dVector<T>& dvector2)
	{
		dVector<T> tempVector;
		tempVector = dvector1;
		tempVector -= dvector2;
		return tempVector;
	}


	class dVector3d {
	public:
		friend class dVector<double>;
		dVector3d(std::vector<double>& vector) {
			if (vector.size() != 3) {
				throw std::invalid_argument("invalid size in dVector3d");
			}
			else {
				dvector = new dVector<double>(vector);
			}
		}

		dVector3d(double x, double y, double z) {
			std::vector<double> tVector = { x,y,z }; dvector = new dVector<double>(tVector); 
		}

		dVector3d(const dVector3d& copy_vector) {
			dvector = new dVector<double>((*copy_vector.dvector)); 
		}

		dVector3d() {
			std::vector<double> vector = { 1,1,1 };
			dvector = new dVector<double>(vector);
		};

		~dVector3d() {
			delete dvector; 
		};

		dVector3d& operator= (const dVector3d& dVector_) {
			if (dvector == dVector_.dvector) {
				return *this; 
			}
			else {
				delete dvector;
				dvector = new dVector<double>((*dVector_.dvector));
				return *this;
			}
		};

		dVector3d& operator+= (const dVector3d& dVector) {
			*(this->dvector) += *dVector.dvector;
			return *this;
		};

		dVector3d& operator-= (const dVector3d& dVector) {
			*(this->dvector) -= *dVector.dvector;
			return *this;
		};

		void PrintVector() {(*dvector).PrintVector();};

	private:
		dVector<double>* dvector; 
	};

	inline dVector3d operator+(const dVector3d& dvector1, const dVector3d& dvector2)
	{
		dVector3d tempVector;
		tempVector = dvector1;
		tempVector += dvector2;
		return tempVector;
	}

	inline dVector3d operator-(const dVector3d& dvector1, const dVector3d& dvector2)
	{
		dVector3d tempVector;
		tempVector = dvector1;
		tempVector -= dvector2;
		return tempVector;
	}

	class dVector4d {
	public:
		friend class dVector<double>;
		dVector4d(std::vector<double>& vector) {
			if (vector.size() != 4) {
				throw std::invalid_argument("invalid size in dVector3d");
			}
			else {
				dvector = new dVector<double>(vector);
			}
		}

		dVector4d(double x = 1, double y = 1, double z = 1, double t = 1) {
			std::vector<double> tVector = { x,y,z,t}; dvector = new dVector<double>(tVector);
		}

		dVector4d(const dVector4d& copy_vector) {
			dvector = new dVector<double>((*copy_vector.dvector));
		}

		~dVector4d() {
			delete dvector;
		};

		dVector4d& operator= (const dVector4d& dVector_) {
			if (dvector == dVector_.dvector) {
				return *this;
			}
			else {
				delete dvector;
				dvector = new dVector<double>((*dVector_.dvector));
				return *this;
			}
		};

		dVector4d& operator+= (const dVector4d& dVector) {
			*(this->dvector) += *dVector.dvector;
			return *this;
		};

		dVector4d& operator-= (const dVector4d& dVector) {
			*(this->dvector) -= *dVector.dvector;
			return *this;
		};

		void PrintVector() { (*dvector).PrintVector(); };

	private:
		dVector<double>* dvector;
	};

	inline dVector4d operator+(const dVector4d& dvector1, const dVector4d& dvector2)
	{
		dVector4d tempVector;
		tempVector = dvector1;
		tempVector += dvector2;
		return tempVector;
	}

	inline dVector4d operator-(const dVector4d& dvector1, const dVector4d& dvector2)
	{
		dVector4d tempVector;
		tempVector = dvector1;
		tempVector -= dvector2;
		return tempVector;
	}

}