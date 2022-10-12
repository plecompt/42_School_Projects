using System;

namespace ExpertSystem
{
    public class Data : IEquatable<Data>, ICloneable
    {
        public bool type { get; set; } //char ou operande
        public char nom { get; set; } //char AB 1 2 + | ^ etcetc
        public bool value { get; set; } // true false
        public bool eol { get; set; } //fin de ligne

        public bool Equals(Data other)
        {
            if (other is null)
                return false;

            return this.type == other.type && this.nom == other.nom && this.value == other.value && this.eol == other.eol;
        }

        public override bool Equals(object obj) => Equals(obj as Data);
        public override int GetHashCode() => (type, nom, value, eol).GetHashCode();

        public object Clone()
        {
            return new Data
            {
                type = this.type,
                nom = this.nom,
                value = this.value,
                eol = this.eol
            };
        }
    }
}
