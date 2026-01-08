
function Count(str)
{
    let iCnt = 0;
    let iCount = 0;

    for(iCnt = 0; iCnt < str.length; iCnt++)
    {
        if(str.charAt(iCnt) == 'l')
        {
            iCount++;
        }
    }
    return iCount;
}

function main()
{
    let Data = "Hello";
    let iRet = 0;

    iRet = Count(Data);

    console.log(iRet);

}

main();

