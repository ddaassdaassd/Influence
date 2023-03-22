namespace WindowsFormsApplication1
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.buttonRegistrarte = new System.Windows.Forms.Button();
            this.buttonIniciarSesion = new System.Windows.Forms.Button();
            this.textBoxUsuario = new System.Windows.Forms.TextBox();
            this.textBoxContraseña = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // buttonRegistrarte
            // 
            this.buttonRegistrarte.Location = new System.Drawing.Point(250, 397);
            this.buttonRegistrarte.Name = "buttonRegistrarte";
            this.buttonRegistrarte.Size = new System.Drawing.Size(140, 49);
            this.buttonRegistrarte.TabIndex = 0;
            this.buttonRegistrarte.Text = "Registrarte";
            this.buttonRegistrarte.UseVisualStyleBackColor = true;
            this.buttonRegistrarte.Click += new System.EventHandler(this.buttonRegistrarte_Click);
            // 
            // buttonIniciarSesion
            // 
            this.buttonIniciarSesion.Location = new System.Drawing.Point(250, 317);
            this.buttonIniciarSesion.Name = "buttonIniciarSesion";
            this.buttonIniciarSesion.Size = new System.Drawing.Size(140, 52);
            this.buttonIniciarSesion.TabIndex = 1;
            this.buttonIniciarSesion.Text = "Iniciar sesion";
            this.buttonIniciarSesion.UseVisualStyleBackColor = true;
            this.buttonIniciarSesion.Click += new System.EventHandler(this.buttonIniciarSesion_Click);
            // 
            // textBoxUsuario
            // 
            this.textBoxUsuario.Location = new System.Drawing.Point(325, 173);
            this.textBoxUsuario.Name = "textBoxUsuario";
            this.textBoxUsuario.Size = new System.Drawing.Size(140, 26);
            this.textBoxUsuario.TabIndex = 2;
            //this.textBoxUsuario.TextChanged += new System.EventHandler(this.textBoxUsuario_TextChanged);
            // 
            // textBoxContraseña
            // 
            this.textBoxContraseña.Location = new System.Drawing.Point(325, 235);
            this.textBoxContraseña.Name = "textBoxContraseña";
            this.textBoxContraseña.Size = new System.Drawing.Size(140, 26);
            this.textBoxContraseña.TabIndex = 3;
            //this.textBoxContraseña.TextChanged += new System.EventHandler(this.textBoxContraseña_TextChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(151, 173);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(102, 29);
            this.label1.TabIndex = 4;
            this.label1.Text = "Usuario:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(151, 235);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(130, 29);
            this.label2.TabIndex = 5;
            this.label2.Text = "Contraeña:";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(710, 559);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textBoxContraseña);
            this.Controls.Add(this.textBoxUsuario);
            this.Controls.Add(this.buttonIniciarSesion);
            this.Controls.Add(this.buttonRegistrarte);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button buttonRegistrarte;
        private System.Windows.Forms.Button buttonIniciarSesion;
        private System.Windows.Forms.TextBox textBoxUsuario;
        private System.Windows.Forms.TextBox textBoxContraseña;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
    }
}

