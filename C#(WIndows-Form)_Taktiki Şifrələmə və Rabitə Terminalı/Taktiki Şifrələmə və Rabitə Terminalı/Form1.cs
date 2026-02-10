using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using uPLibrary.Networking.M2Mqtt;
using uPLibrary.Networking.M2Mqtt.Messages;


namespace Taktiki_Şifrələmə_və_Rabitə_Terminalı
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            client = new MqttClient("broker.hivemq.com");
            client.Connect(Guid.NewGuid().ToString());
        }

        MqttClient client;
        string key = "AZ-DEF-2025"; // Şifrə açarı
        private void btnSend_Click(object sender, EventArgs e)
        {
            string originalMessage = txtMessage.Text;

            // XOR ilə Şifrələmə
            byte[] encryptedBytes = EncryptDecrypt(originalMessage, key);

            if (client.IsConnected)
            {
                client.Publish("milli_mudafie/terminal_001", encryptedBytes);
                string status = $"[{DateTime.Now:HH:mm:ss}] Göndərildi: {originalMessage}";
                listBox1.Items.Add(status);
                listBox1.TopIndex = listBox1.Items.Count - 1;
            }else
            {
                MessageBox.Show("Bağlantı kəsildi! Yenidən qoşulun.");
            }
        }

        byte[] EncryptDecrypt(string text, string key)
        {
            byte[] res = new byte[text.Length];
            for (int i = 0; i < text.Length; i++)
            {
                res[i] = (byte)(text[i] ^ key[i % key.Length]);
            }
            return res;
        }
    }
}
