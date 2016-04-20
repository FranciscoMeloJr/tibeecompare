class MyTestLayer
{
	//This class is a test for calling another library using JNI
	public native void printmsg(double a, double b, double c);
	static 
	{
		System.loadLibrary("JNILayer");
	}

	public static void main(String[] args)
	{
		MyTestLayer hello = new MyTestLayer();
		
                for (String s: args) {
         	   System.out.println(s);
	        }
		
		if(args[0].equals("v")){
			hello.printmsg(Double.parseDouble(args[1]),Double.parseDouble(args[2]),Double.parseDouble(args[3]));
		}
			
	}
}
