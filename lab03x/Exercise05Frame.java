import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.List;
import java.util.concurrent.ExecutionException;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.SwingWorker;

public class Exercise05Frame extends JFrame {
  private JLabel myLabel = new JLabel("10");
  private JButton myButton = new JButton("Countdown");

  public Exercise05Frame(String title) {
    super(title);

    setLayout(new GridBagLayout());

    GridBagConstraints gc = new GridBagConstraints();

    gc.fill = GridBagConstraints.NONE;
    gc.gridx = 0;
    gc.gridy = 0;
    add(myLabel, gc);

    gc.gridx = 0;
    gc.gridy = 2;
    add(myButton, gc);

    myButton.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent arg0) { countDown(); }
    });

    setSize(300, 300);
    setDefaultCloseOperation(EXIT_ON_CLOSE);
    setLocationRelativeTo(null);
    setVisible(true);
  }

  public void countDown() {
    SwingWorker<Integer, Integer> worker = new SwingWorker<Integer, Integer>() {
      protected Integer doInBackground() throws Exception {
        for (int i = 10; i > 0; i--) {
          Thread.sleep(1000);
          System.out.println(i);
          publish(i);
        }
        return -1;
      }

      @Override
      protected void process(List<Integer> chunks) {
        Integer value = chunks.get(chunks.size() - 1);
        myLabel.setText(String.valueOf(value));
      }

      @Override
      protected void done() {
        try {
          Integer status = get();
          System.out.println("Status " + status);
          myLabel.setText("Boom!!!");
        } catch (InterruptedException | ExecutionException e) {
          e.printStackTrace();
        } 
      }
    };
    worker.execute();
  }
}
