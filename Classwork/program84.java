import java.util.*;

class Number
{
    public boolean CheckPerfect(int iNo)
    {
        int i = 0;
        int isum = 0;

        // updater
        
        if(iNo < 0)
        {
            iNo = -iNo;
        }
                                        // change
        for(i = 1; (i <= (iNo / 2)) && (isum < iNo); i++)
        {
            if((iNo % i) == 0)
            {
                isum = isum + i;
            }

        }

        return(isum == iNo);    // Change
    }

} // End of Number 

class program84
{
    public static void main(String A[])
    {
        int iValue = 0;
        boolean bRet = false;

        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter number : ");
        iValue = sobj.nextInt();

        Number nobj = new Number();
        bRet = nobj.CheckPerfect(iValue);

        if(bRet == true)
        {
            System.out.println(iValue+" is perfect number");
        }
        else
        {
            System.out.println(iValue+" is not perfect number");
        }        

        // Important 
        
        sobj = null;
        nobj = null;

        System.gc();
    }
}