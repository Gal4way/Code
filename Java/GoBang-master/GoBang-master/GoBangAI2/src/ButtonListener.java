//���ð�ť��������ButttonLitener��
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JComboBox;

public class ButtonListener implements GoBangconfig,ActionListener{
	public GoBangframe gf;
	public JComboBox box;
	
	public ButtonListener(GoBangframe gf,JComboBox box) {
		this.gf=gf;
		this.box=box;
	}

	public void actionPerformed(ActionEvent e) {
		if(e.getActionCommand().equals("��ʼ����Ϸ")) {
		    for(int i=0;i<gf.isAvail.length;i++)
			   for(int j=0;j<gf.isAvail[i].length;j++)
			    	 gf.isAvail[i][j]=0;
		    gf.repaint();
			gf.turn=1;
		}
		else if(e.getActionCommand().equals("����")) {
			if((gf.ChessPositonList.size()>1)&&(gf.turn!=0)) {
				ChessPosition l=new ChessPosition();
				l=gf.ChessPositonList.remove(gf.ChessPositonList.size()-1);
				gf.isAvail[l.Listi][l.Listj]=0;
				if(gf.turn==1) gf.turn++;
				else gf.turn--;
				gf.repaint();
			}
			else {
				gf.PopUp("������ʾ","���ܻ���!");
			}
		}
		else if(e.getActionCommand().equals("����")) {
			if(gf.turn==1) gf.PopUp("��Ϸ���","�׷�Ӯ");
			else gf.PopUp("��Ϸ���","�ڷ�Ӯ");
		    gf.turn=0;
		}
		else if(box.getSelectedItem().equals("�˻���ս")) {
			 gf.ChooseType=1;
			 gf.turn=0;
		}
		else if(box.getSelectedItem().equals("���˶�ս")){
			 gf.ChooseType=0;
			 gf.turn=0;
		}
	}
	
}
