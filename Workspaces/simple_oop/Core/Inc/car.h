/*
 * car.h
 *
 *  Created on: Feb 11, 2023
 *      Author: ductrung1802
 *       Email: trung.lyduc18@gmail.com
 *       Brief: OOP Example class
 */

#ifndef CAR_H
#define CAR_H

#include <string>
#include <stdexcept>

#ifdef __cplusplus
extern "C"
#endif

enum fuelType {GASOLINE=0, DIESEL=1, ELECTRIC=2, HYBRID=3};

class Car {
private:
	uint8_t * brand;
	uint8_t * model;
	fuelType fuel_type;
	uint8_t * fuel_type_tag;
	int price;
	int max_speed;
	bool status;
	uint8_t * toFuelTypeTag(fuelType fuel_type);

public:
	Car(const char * brand, const char * model, fuelType fuel_type, int price, int max_speed, bool status);
	uint8_t * startEngine ();
	uint8_t * accelerate ();
	uint8_t * decelerate ();
	uint8_t * stopEngine ();

	// brand
	void setBrand(uint8_t * brand);
	uint8_t * getBrand();

	// model
	void setModel(uint8_t * model);
	uint8_t * getModel();

	// fuel_type
	void setFuelType(fuelType fuel_type);
	uint8_t * getFuelType();

	// price
	void setPrice(int price);
	int getPrice();

	// max_speed
	void setMaxSpeed(int max_speed);
	int getMaxSpeed();

	// status
	void setStatus(bool status);
	bool getStatus();
};

#ifdef __cplusplus

#endif

#endif /* CAR_H */
