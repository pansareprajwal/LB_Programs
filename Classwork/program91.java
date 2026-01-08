import java.util.*;

class Digit
{
    public int SumDigits(int iNo)
    {
        int iDigit = 0;
        int iSum = 0;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iSum += iDigit;
            iNo = iNo / 10;
        }
        return iSum;
    }

    
}

class program91
{
    public static void main(String A[])
    {
        int iValue, iRet = 0;

        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter number : ");
        iValue = sobj.nextInt();

        Digit dobj = new Digit();
        iRet = dobj.SumDigits(iValue); 

        System.out.println("Sum of Digits : "+iRet);    

        // Important 
        
        sobj = null;
        dobj = null;

        System.gc();
    }
}