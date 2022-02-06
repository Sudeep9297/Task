public class LaunchCompany {
	
		public static void main(String[] args) {
		 HR h1=new HR();
		 Finance f1=new Finance();
		 Support s1=new Support();
		 h1.setEmp_id(1001);
		 h1.setDep_name("Human Resource");
		 System.out.println(h1.getEmp_id());
		 System.out.println(h1.getDep_name());
		 h1.func1();
		 h1.func2();
		 System.out.println("---------------------------------------------------------------------------");
		 f1.setEmp_id(1002);
		 f1.setDep_name("Finance Department");
		 System.out.println(f1.getEmp_id());
		 System.out.println(f1.getDep_name());
		 f1.func1();
		 f1.func2();
		 System.out.println("---------------------------------------------------------------------------");
		 s1.setEmp_id(1003);
		 s1.setDep_name("Support Department");
		 System.out.println(s1.getEmp_id());
		 System.out.println(s1.getDep_name());
		 s1.func1();
		 s1.func2();
	}
}
