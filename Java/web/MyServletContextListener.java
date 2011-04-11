import javax.servlet.ServletContextListener;
import javax.servlet.ServletContextEvent;
import javax.servlet.*;

/*
This J2EE tip demonstrates use of ServletContextListener. This event
class handles notifications about changes to the servlet context of
the Web application that they are part of. This can be explained as 
if someone is present on the server and dynamically informing us about 
the events that are occuring on the server. There acquire need of Listners. 
Therefore, ServletContextListner is helpful in informing about context 
Initilazation and destruction.
*/

public	class MyListener implements ServletContextListener {

	private ServletContext context = null;


	public void contextDestroyed(ServletContextEvent event){
		//Output a simple message to the server's console
		System.out.println("The Simple Web App. Has Been Removed");
		this.context = null;

	}


	public void contextInitialized(ServletContextEvent event){
		this.context = event.getServletContext();

		//Output a simple message to the server's console
		System.out.println("The Simple Web App. Is Ready");

	}
}

<web-app>
	<listener>
		<listener-class>
			com.listeners.MyContextListener
		</listener-class>
	</listener>
	<servlet/>
	<servlet-mapping/>
</web-app> 