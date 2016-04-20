class MyTestLayer
{
	//This class is a test for calling another library using JNI and a shared library
	public native double volume(double a, double b, double c);
	public native void printmsg(char[] a);

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
			hello.volume(Double.parseDouble(args[1]),Double.parseDouble(args[2]),Double.parseDouble(args[3]));
		}
		if(args[0].equals("p")){
			 
			char[] charArray = args[1].toCharArray();
			hello.printmsg(charArray);
		}
			
	}
}
