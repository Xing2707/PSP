package EVA2.TCP_UTP.TCP.MultiThread;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {

	private static final double BASE = 100;
	private static final String SALIR = "salir";

	public static void main(String[] args) {
		ServerSocket server;
		try {
			server = new ServerSocket(1234);
			while(true) {
				// Espera cliente
				Socket socket = server.accept();

				new Thread(()->{
					try {
						boolean condition = true;
						DataInputStream in = null;
						DataOutputStream out = null;
						String mesage = "";
						String newMesage ="";

						while (condition) {
							in = new DataInputStream(socket.getInputStream());
							out = new DataOutputStream(socket.getOutputStream());
							BufferedReader reader = new BufferedReader(new InputStreamReader(in));
							while((mesage = reader.readLine()) != null){
								newMesage.concat(mesage);
							};

							if(mesage.toLowerCase() == SALIR){
								condition = false;
								socket.close();
							}else{
								try {
									Thread.sleep(2000);
								} catch (Exception e) {
									e.printStackTrace();
								}
								out.writeUTF(String.valueOf((int) ((Math.random() * BASE - 1) + 1)));
								out.flush();
							}
							in.close();
							out.close();
							socket.close();
						}
					} catch (IOException e) {
						e.printStackTrace();
					}
					
				}).start();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}

}