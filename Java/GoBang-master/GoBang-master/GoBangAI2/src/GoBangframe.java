import javax.swing.*;
import java.awt.Dimension;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.Graphics;
import java.awt.Image;
import java.util.ArrayList;
import java.util.HashMap;
public class GoBangframe extends JPanel implements GoBangconfig{
	public Graphics g;
	public int[][] isAvail=new int [column][row];
	public ArrayList<ChessPosition>ChessPositonList=new ArrayList<ChessPosition>();
	public int turn=0;
	public int ChooseType=0;
	public int[][] weightArray=new int[column][row];
	public static HashMap<String,Integer> map = new HashMap<String,Integer>();
	static {
		
		//����ס
		map.put("01", 25);//��1��
		map.put("02", 22);//��1��
		map.put("001", 17);//��1��
		map.put("002", 12);//��1��
		map.put("0001", 17);//��1��
		map.put("0002", 12);//��1��
		
		map.put("0102",25);//��1����15
		map.put("0201",22);//��1����10
		map.put("0012",15);//��1����15
		map.put("0021",10);//��1����10
		map.put("01002",25);//��1����15
		map.put("02001",22);//��1����10
		map.put("00102",17);//��1����15
		map.put("00201",12);//��1����10
		map.put("00012",15);//��1����15
		map.put("00021",10);//��1����10

		map.put("01000",25);//��1����15
		map.put("02000",22);//��1����10
		map.put("00100",19);//��1����15
		map.put("00200",14);//��1����10
		map.put("00010",17);//��1����15
		map.put("00020",12);//��1����10
		map.put("00001",15);//��1����15
		map.put("00002",10);//��1����10

		//��ǽ��ס
		map.put("0101",65);//��2����40
		map.put("0202",60);//��2����30
		map.put("0110",80);//��2����40
		map.put("0220",76);//��2����30
		map.put("011",80);//��2����40
		map.put("022",76);//��2����30
		map.put("0011",65);//��2����40
		map.put("0022",60);//��2����30
		
		map.put("01012",65);//��2����40
		map.put("02021",60);//��2����30
		map.put("01102",80);//��2����40
		map.put("02201",76);//��2����30
		map.put("01120",80);//��2����40
		map.put("02210",76);//��2����30
		map.put("00112",65);//��2����40
		map.put("00221",60);//��2����30

		map.put("01100",80);//��2����40
		map.put("02200",76);//��2����30
		map.put("01010",75);//��2����40
		map.put("02020",70);//��2����30
		map.put("00110",75);//��2����40
		map.put("00220",70);//��2����30
		map.put("00011",75);//��2����40
		map.put("00022",70);//��2����30
		
		//����ס
		map.put("0111",150);//��3����100
		map.put("0222",140);//��3����80
		
		map.put("01112",150);//��3����100
		map.put("02221",140);//��3����80
	
		map.put("01110", 1100);//��3��
		map.put("02220", 1050);//��3��
		map.put("01101",1000);//��3����130
		map.put("02202",800);//��3����110
		map.put("01011",1000);//��3����130
		map.put("02022",800);//��3����110
		
		map.put("01111",3000);//4����300
		map.put("02222",3500);//4����280
	}


	public static void main(String args[]) {
		GoBangframe gf=new GoBangframe();//��ʼ��һ�����������Ķ���
		gf.initUI();//���÷������н���ĳ�ʼ��
	}
	
	public void initUI() {
		//��ʼ��һ������,�����ñ����С������
		JFrame jf=new JFrame();
		jf.setTitle("������");
		jf.setSize(765*2,635*2);
		jf.setLocationRelativeTo(null);
		jf.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
		
		jf.setLayout(new BorderLayout());//���ö�������JFrameΪ��ܲ���
		
		Dimension dim1=new Dimension(150*2,0);//�����Ұ벿�ֵĴ�С
		Dimension dim3=new Dimension(550*2,0);//������벿�ֵĴ�С
		Dimension dim2=new Dimension(140*2,40*2);//�����ұ߰�ť����Ĵ�С

		this.setPreferredSize(dim3);
		this.setBackground(Color.LIGHT_GRAY);
		jf.add(this,BorderLayout.CENTER);
		
		//ʵ���ұߵ�JPanel��������
		JPanel jp=new JPanel();
		jp.setPreferredSize(dim1);
		jp.setBackground(Color.white);
		jf.add(jp,BorderLayout.EAST);
		jp.setLayout(new FlowLayout());

		String[] butname= {"��ʼ����Ϸ","����","����"};
		JButton[] button=new JButton[3];

		for(int i=0;i<butname.length;i++) {
			button[i]=new JButton(butname[i]);
			button[i].setPreferredSize(dim2);
			jp.add(button[i]);
		}

		String[] boxname= {"���˶�ս","�˻���ս"};
		JComboBox box=new JComboBox(boxname);
		box.setPreferredSize(dim2);
		jp.add(box);
		ButtonListener butListen=new ButtonListener(this,box);

		for(int i=0;i<butname.length;i++) {
			button[i].addActionListener(butListen);
		}
		

		box.addActionListener(butListen);
		
		frameListener fl=new frameListener();
		fl.setGraphics(this);
		this.addMouseListener(fl);
		
		jf.setVisible(true);
	}
	
	public void PopUp(String top,String result) {
		JOptionPane jo=new JOptionPane();
		jo.showMessageDialog(null, result, top, JOptionPane.PLAIN_MESSAGE);
	}

	public void paint(Graphics g) {
		super.paint(g);
		
		Image icon= new ImageIcon("chessboard.jpg").getImage();
		g.drawImage(icon, 0, 0, row*size, column*size, null);
		
		//�ػ������
		for(int i=0;i<row;i++) {
			for(int j=0;j<column;j++) {
				if(isAvail[i][j]==1) {
					int countx=size*j+x;
					int county=size*i+y;
					g.drawImage(blackchess,countx-size/2, county-size/2, size, size,null);
				}
				else if(isAvail[i][j]==2) {
					int countx=size*j+x;
					int county=size*i+y;
					g.drawImage(whitechess,countx-size/2, county-size/2, size, size,null);
				}
			}
		}
	}
	
}
