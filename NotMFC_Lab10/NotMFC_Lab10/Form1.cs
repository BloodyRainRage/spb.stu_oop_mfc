using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace NotMFC_Lab10 {
    public partial class Form1 : Form {
        public Form1()
        {
            InitializeComponent();
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog open = new OpenFileDialog();
            open.Filter = "Bitmap picture files (*.bmp)|*.bmp";
            if (open.ShowDialog() == DialogResult.OK) {
                // display image in picture box  
                this.BackgroundImage = new Bitmap(open.FileName);
                this.BackgroundImageLayout = ImageLayout.Zoom;                
                // image file path  
                this.Text = open.FileName;

                MessageBox.Show(open.FileName);
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
