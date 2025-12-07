#include <iostream>
#include <vector>
#include <memory>

class Animal {
protected:
	std::string name;
	int age;

public:
	Animal(const std::string& name, int age) : name(name), age(age) {}

	virtual ~Animal() {
		std::cout << name << " has been removed from the zoo.\n";
	}

	virtual void makeSound() const {
		std::cout << name << " makes a heneric animal sound. \n";
	}

	virtual void eat() const = 0;

	void sleep() const {
		std::cout << name << " is sleeping... Zzz\n";
	}

	std::string getName() const { return name; }
	int getAge() const { return age; }
};

class Lion : public Animal {
private:
	int maneLength;

public:
	Lion(const std::string& name, int age, int maneLength)
		: Animal(name, age), maneLength(maneLength) {}

	void makeSound() const override {
		std::cout << name << " roars loudly! ROAR!\n";
	}

	void eat() const override {
		std::cout << name << " eats meat (carnivore).\n";
	}

	void hunt() const {
		std::cout << name << " is hunting with " << maneLength << "cm mane!\n";
	}
};

class Elephant : public Animal {
private:
	double tuskLength;

public:
	Elephant(const std::string& name, int age, double tuskLength)
		: Animal(name, age), tuskLength(tuskLength) {}

	void makeSound() const override {
		std::cout << name << " trumpets! TOOT TOOT!\n";
	}

	void eat() const override {
		std::cout << name << " eats plants (herbivore).\n";
	}

	void sprayWater() const {
		std::cout << name << " sprays water with its trunk!\n";
	}
};

class Bird : public Animal {
private:
	double wingspan;
	bool canFly;

public:
	Bird(const std::string& name, int age, double wingspan, bool canFly)
		: Animal(name, age), wingspan(wingspan), canFly(canFly) {}

	void makeSound() const override {
		std::cout << name << " chirps! Chirp Chirp!\n";
	}

	void eat() const override {
		std::cout << name << " eats seeds and insects.\n";
	}

	void fly() const {
		if (canFly) {
			std::cout << name << " flies with " << wingspan << "cm wingspan!\n";
		}
		else {
			std::cout << name << " cannot fly (flightless bird).\n";
		}
	}
};

int main() {
	std::cout << "=== ZOO MANAGEMENT SYSTEM ===\n\n";

	std::vector<std::unique_ptr<Animal>> zoo;

	zoo.push_back(std::make_unique<Lion>("Simba", 5, 30));
	zoo.push_back(std::make_unique<Elephant>("Dumbo", 10, 2.5));
	zoo.push_back(std::make_unique<Bird>("Tweety", 2, 15.0, true));
	zoo.push_back(std::make_unique<Bird>("Pengu", 3, 10.0, false));
	zoo.push_back(std::make_unique<Lion>("Nala", 4, 25));

	std::cout << "=== ANIMAL SOUNDS (Polymorphism) ===\n";
	for (const auto& animal : zoo) {
		animal->makeSound();
	}

	std::cout << "\n=== FEEDING TIME ===\n";
	for (const auto& animal : zoo) {
		animal->eat();
	}

	std::cout << "\n=== SPECIFIC BEHAVIOURS ===\n";
	for (const auto& animal : zoo) {
		if (auto lion = dynamic_cast<Lion*>(animal.get())) {
			lion->hunt();
		}
		else if (auto elephant = dynamic_cast<Elephant*>(animal.get())) {
			elephant->sprayWater();
		}
		else if (auto bird = dynamic_cast<Bird*>(animal.get())) {
			bird->fly();
		}
	}

	std::cout << "\n=== ZOO INFORMATION ===\n";
	std::cout << "Total animals: " << zoo.size() << "\n";
	for (const auto& animal : zoo) {
		std::cout << "- " << animal->getName()
			<< " (Age: " << animal->getAge() << ")\n";
	}

	std::cout << "\n=== ZOO ClOSING ===\n";

	return 0;
}