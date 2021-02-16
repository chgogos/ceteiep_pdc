import javax.swing.SwingUtilities;

public class Exercise05Swing {

	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {

			@Override
			public void run() {
				new Exercise05Frame("CountDown");
			}
		});
	}
}
