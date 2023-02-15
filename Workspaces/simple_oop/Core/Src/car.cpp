/*
 * car.cpp
 *
 *  Created on: Feb 11, 2023
 *      Author: ductrung1802
 *       Email: trung.lyduc18@gmail.com
 *       Brief: OOP Example class
 */

#include "car.h"

Car::Car(const char * brand, const char * model, fuelType fuel_type, int price, int max_speed, bool status){
	this->brand = (uint8_t *)brand;
	this->model = (uint8_t *)model;
	this->fuel_type_tag = this->toFuelTypeTag(fuel_type);
	this->price = price;
	this->max_speed = max_speed;
	this->status = status;
}

uint8_t * Car::startEngine()
{
	static uint8_t value[] = "startEngine";
	return value;
}

uint8_t * Car::accelerate()
{
	static uint8_t value[] = "accelerate";
	return value;
}

uint8_t * Car::decelerate()
{
	static uint8_t value[] = "decelerate";
	return value;
}

uint8_t * Car::stopEngine()
{
	static uint8_t value[] = "stopEngine";
	return value;
}

void Car::setBrand(uint8_t * brand) {
	this->brand = brand;
}

uint8_t * Car::getBrand() {

	return this->brand;
}

void Car::setModel(uint8_t * model) {
	this->model = model;
}

uint8_t * Car::getModel() {
	return this->model;
}

uint8_t * Car::toFuelTypeTag(fuelType fuel_type) {
	switch(this->fuel_type) {
	case GASOLINE:
		this->fuel_type_tag = (uint8_t *)"GASOLINE";
		break;
	case DIESEL:
		this->fuel_type_tag = (uint8_t *)"DIESEL";
		break;
	case ELECTRIC:
		this->fuel_type_tag = (uint8_t *)"ELECTRIC";
		break;
	case HYBRID:
		this->fuel_type_tag = (uint8_t *)"HYBRID";
		break;
	default:
		this->fuel_type_tag = (uint8_t *)"GASOLINE";
	}
	return this->fuel_type_tag;
}

void Car::setFuelType(fuelType fuel_type) {
	this->fuel_type_tag = this->toFuelTypeTag(fuel_type);
}

uint8_t * Car::getFuelType() {
	return this->fuel_type_tag;
}

void Car::setPrice(int price) {
	if (price <= 0) {
		throw std::invalid_argument("Price must be a positive number!");
	} else {
		this->price = price;
	}
}

int Car::getPrice() {
	return this->price;
}

void Car::setMaxSpeed(int max_speed) {
	if (max_speed <= 0) {
		throw std::invalid_argument("Max speed must be a positive number!");
	} else {
		this->max_speed = max_speed;
	}
}

int Car::getMaxSpeed() {
	return this->max_speed;
}

void Car::setStatus(bool status) {
	this->status = status;
}

bool Car::getStatus() {
	return this->status;
}

