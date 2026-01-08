
class Arithmetic
{

    constructor(A, B)      
    {
        this.No1 = A;
        this.No2 = B;
    }

    Add()
    {
        return this.No1 + this.No2;
    }

    Sub()
    {
        return this.No1 - this.No2;
    }


}

function main()
{
    let obj = new Arithmetic(10,20);
    let iRet = 0;

    iRet = obj.Add();
    console.log("Addition is :",iRet);
    
    iRet = obj.Sub();
    console.log("Substraction is :",iRet);

}

main();

