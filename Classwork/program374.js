// Not allowed to write two constructor at time
class Demo
{
    constructor()       // Default
    {
        this.No1 = 0;
        this.No2 = 0;

        console.log("Inside Default constructor");
    }

    constructor(A, B)       // Default
    {
        this.No1 = A;
        this.No2 = B;

        console.log("Inside Parametrized constructor");
    }
}

function main()
{
    let obj1 = new Demo();
    let obj2 = new Demo(10,20);
}

main();

