# Gym_Management_System-OOP-
This project implements a Gym Management System using object-oriented programming principles in C++. The system includes classes for managing gym facilities, equipment, members, trainers.
## UML Diagram
![Picture1](https://github.com/AliAdanPro/Gym_Management_System-OOP-/assets/142499778/6676802e-7d01-431f-b205-bd661642ec00)
## Explanation
+ The hash shows protected data members.
+ The underline shows static data members or functions.
+ The plus shows public functions.
+ The strike through shows pure virtual functions.
+ The negative shows private data members.
## Features

- **File Handling**: Implements file I/O for data storage and retrieval.
- **Exception Handling**: Ensures robust error handling during file operations.
- **Polymorphism**: Utilizes polymorphism (Dynamic Binding) through abstract base classes and virtual functions.
- **Composition and Inheritance**: Demonstrates object-oriented design principles.
## Classes
### Gym
- Manages overall gym operations.
- Tracks gym details such as name, contact number, and equipment.

### Equipment (Composition with Gym)
- Stores information about gym equipment.
- Tracks equipment name, model, and quantity.

### Address (Composition with Gym and Person)
- Manages address information for gyms and personnel.
- Includes street number, sector, house number, and city.

### Person (Abstract Base Class)
- Base class for Trainers and Members.
- Includes common attributes like ID, name, contact number, and address.
- Implements virtual functions for polymorphism.

### Trainer (Inherits from Person)
- Represents gym trainers.
- Includes specialization details.

### Member (Inherits from Person)
- Represents gym members.
- Tracks membership details and billing.

### Invoice (Composition with Member)
- Manages billing details for gym members.
- Includes trainer charges, gym fees, and total amount.
## Attributes
### Gym
+ Name
+ Contact_no
+ count_equip
+ count_gym
+ numEquipments
+ *equipment
+ address
### Equipment
+ name
+ model
+ Quantity
+ Total_Equipment
### Address
+ street_no
+ sector
+ house_no
+ city
### Person
+ *id
+ name
+ contact_no
+ address
### Member
+ count_members
+ trainer_required
+ bill
### Trainer
+ specialization
+ count_trainers
### Invoice
+ trainer_charges
+ gym_fee
+ total_amount
## Usage
## Gym
### Gym():
This is the constructor of the Gym Class
### Gym(Name: string, contact:int, name: string, model: string, Quantity: int, street_no: int, sector: string, house_no: int, city: string, *equipments: Equipment, numEquipments: int):
This is the parametarized constructor of the Gym class.
### Get_Gym(): string
This retrieves (Accessor Method) all the gym details but first we need to set the gym details.
### Set_Gym(Name: string, contact: int, name: string, model: string, Quantity: int, street_no: int, sector: string, house_no: int, city: string, *equipments: Equipment, numEquipments: int): void
This sets (Accessor Method) all the gym details.
### <<friend>>ostream & operator<<(ostream &, const Gym&)
This is operator overloading function and we can show output by directly using object.
### ~Gym()
This is the destructor to deallocate the pointer variables manually.
### getcountequip(): int
This gets the count of the equipment records present in the txt file.
### AddEquipment(): void
This will add the Equipment data into the file that user has inputted.
### viewequip(): void
This will view the equipment details from file.
### Searchequip(): void
This will search a specific record from the equipment file.
### updateequip(): void
This can update a specific value from the equipment file.
### deleteequip(): void
This can delete a equipment record from file.
### getcountgym(): int
This gets the count of the gym records present in the txt file.
### AddDatagym(): void
This will add the gym data into the file that user has inputted.
### viewgym(): void
This will view the gym details from file.
### Searchgym(): void
This will search a specific record from the gym file.
### updategym(): void
This can update a specific value from the gym file.
### deletegym(): void
This can delete a gym record from file.
### store_data(): void
This stores the gym data.
### Read_file(): void
This is will read the txt file.
## Equipment
### Equipment():
This is the constructor.
### Equipment(name: string, model: string, quantity: int)
This is the parametarized constructor.
### get_total_Equipment(): int
This will the count of equipment records from txt file.
### Get_Equipment(): string
This will get (Accessor method) the equipment details.
### Set_Equipment(name: string, model: string, quantity: int): void
This will set (Mutator method) the equipment details.
## Address
### Address():
This is the constructor
### Address(stree_no: int, sector: string, house_no: int, city: string):
This is the parametarized constructor.
### Get_Address(): string
This will get (Accessor Method) the address details.
### Set_Address(stree_no: int, sector: string, house_no: int, city: string): void
This will set (Mutator Method) the address details.
## Person
### Person():
This is the constructor
### Person(id: int, name: string, contact_no: int, street_no: int, sector: string, house_no: int, city: string):
This is the parametarized constructor
### tostring(): virtual string
This is gets all the details in string. It tells the constant state. I have made this function as pure virtual and overrided it in child classes.
### ~Person():
This is the destructor to deallocate the pointer variables
### Add_record(): virtual void
This is a pure virtual function and overrided in the child classes. Any pure virtual class I made makes the person class as abstract.
###  view_record(): virtual void
This is a pure virtual function and overrided in the child classes.
### search_record(): virtual void
This is a pure virtual function and overrided in the child classes.
### update_record(): virtual void
This is a pure virtual function and overrided in the child classes.
### delete_record(): virtual void
This is a pure virtual function and overrided in the child classes.
### save_data(): virtual void
This is a pure virtual function and overrided in the child classes.
### read_data(): virtual void
This is a pure virtual function and overrided in the child classes.
## Member
### Member():
This is the constructor.
### Member(Gym_id: int, count_members: int, trainer_required: string, invoice_id: int, trainer_charges: int, gym_fee: int, total_amount: float):
This is the parametarized constructor.
### get_count(): int
This gets the count of the member records from txt file.
### Add_record(): void
This will add the record of member by taking inputs from user.
### view_record(): void
This will the view records of member from txt file.
### search_record(): void
This will search a specific record of member from txt file.
### update_record(): void
This will update a specific value of member from file.
### delete_record(): void
This will delete a specific record of member from file.
### save_data(): void
This will save the details in txt file.
### read_data(): void
This will read data from file.
## Invoice
### Invoice():
This is the constructor.
### Invoice(invoice_id: int, trainer_charges: int, gym_fee: int, total_amount: float):
This is the parametarized constructor.
### Get_invoice(): string
This will get (Accessor Method) the invoice details.
### Set_invoice(invoice_id: int, trainer_charges: int, gym_fee: int, total_amount: float): string
This will set (Mutator Method) the invoice details.
## Trainer
### Trainer():
This is the constructor
### Trainer(specialization: string, id: int, name: string, contact_no: int):
This is the parametarized constructor.
### tostring(): string
This gets the values in string. This tell the constant state of function.
### get_count(): string
This gets count of the records present in trainer file.
### Add_record(): void
This will add the record of trainer by taking inputs from user.
### view_record(): void
This will the view records of trainer from txt file.
### search_record(): void
This will search a specific record of trainer from txt file.
### update_record(): void
This will update a specific value of trainer from file.
### delete_record(): void
This will delete a specific record of trainer from file.
### save_data(): void
This will save the details in txt file.
### read_data(): void
This will read data from file.
## License
Feel Free to use the code and change it any way you want.
