//                       employee.h
//
// An employee class - first inheritance example

class employee {
public:
    employee();
    // PRECONDITION:  none.
    //
    // POSTCONDITION: name is initialized to the null 
    //                string; salary is set to 0 and 
    //                groupno is set to 0.

    employee( const employee& e );
    // PRECONDITION:  none.
    //
    // POSTCONDITION: the constructed object is a copy of e.

    employee( char * n, int s, int g );
    // PRECONDITION:  n should be a null terminated string; 
    //                s should be >= 0, and g should be a 
    //                non-negative integer that represents a 
    //                group number.
    //
    // POSTCONDITION: name will be set to n. salary will be 
    //                the maximum of s and 0; groupno will 
    //                be maximum of g and 0.

    ~employee();
    // PRECONDITION:  none.
    //
    // POSTCONDITION: the employee is properly destroyed.

    // Mutators
    bool salary_set( int s );
    // PRECONDITION:  s must be non-negative.
    //
    // POSTCONDITION: if s is non-negative, salary has 
    //                been set to s and true is returned. 
    //                If s<0, salary is unchanged and 
    //                false is returned.

    void change_group( int g );
    // PRECONDITION:  g must be a non-negative integer that
    //                represents a group number.
    // POSTCONDITION: groupno has been set to g.

    // Accessors
    int get_group() const { return groupno; }
    // PRECONDITION:  none.
    //
    // POSTCONDITION: the group number is returned.

    const char * get_name() const { return name; }
    // PRECONDITION:  none.
    //
    // POSTCONDITION: the name is returned.

    int get_salary() const { return salary; }
    // PRECONDITION:  none.
    //
    // POSTCONDITION: the current salary is returned.
    // Utility Functions

    void print() const;
    // PRECONDITION:  none.
    //
    // POSTCONDITION: the employee information will be displayed
    //                on standard output.

    // Operations
    employee& operator= ( const employee& emp );
    // PRECONDITION:  none.
    //
    // POSTCONDITION: The invoking object will have the same
    //                values as emp.

private:
    int salary;
    char *name;
    int groupno;
};

class manager: public employee {                     // Note 1
public:
    manager( char * n, int s, int g, int o );
    // PRECONDITION:  n must be a null terminated string. s 
    //                and g should be non-negative integers. 
    //                o should represent an office number.
    // POSTCONDITION: a manager object has been created 
    //                with name n, salary s, group g, 
    //                office o, and num_in_group equal to 0.

    bool set_group( employee& e );
    // PRECONDITION:  none. 
    //
    // POSTCONDITION: If the return value is true, e has 
    //                been added to the group. If the return 
    //                value is false, e was not added to the group.

    void print() const;                              // Note 2
    // PRECONDITION:  none.
    //
    // POSTCONDITION: the manager information and the manager's 
    //                group have been displayed on standard output.

private:
    employee *group[10];
    int office;
    int num_in_group;
};
